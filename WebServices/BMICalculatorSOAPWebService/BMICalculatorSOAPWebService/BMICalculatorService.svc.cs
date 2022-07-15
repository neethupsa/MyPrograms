using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.ServiceModel.Web;
using System.Text;

namespace BMICalculatorSOAPWebService
{  
    public class BMICalculatorService : IBMICalculatorService
    {
        public double MyBMI(int height, int weight)
        {
            double bmi = 0.0;
            if (height <= 0)
            {
                return bmi;
            }
            bmi = (Convert.ToDouble(weight) / Convert.ToDouble(height) / Convert.ToDouble(height)) * 703;
            return bmi;
        }

        public BMIStructure MyHealth(int height, int weight)
        {
            BMIStructure bmiResults = new BMIStructure();
            bmiResults.bmiValue = MyBMI(height, weight);

            if(bmiResults.bmiValue < 18)
            {
                bmiResults.risk = "BLUE";
            }
            else if (bmiResults.bmiValue >= 18 && bmiResults.bmiValue < 25)
            {
                bmiResults.risk = "GREEN";
            }
            else if (bmiResults.bmiValue > 25  && bmiResults.bmiValue < 30)
            {
                bmiResults.risk = "PURPLE";
            }
            else if (bmiResults.bmiValue > 30)
            {
                bmiResults.risk = "RED";
            }

            bmiResults.externalLinks = new string[3] { "https://www.cdc.gov/healthyweight/assessing/bmi/index.html",
                                                       "https://www.nhlbi.nih.gov/health/educational/lose_wt/index.htm",
                                                       "https://www.ucsfhealth.org/education/body_mass_index_tool/" };


            return bmiResults;
        }
    }
}
