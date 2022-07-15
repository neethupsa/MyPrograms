using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.ServiceModel.Web;
using System.Text;

namespace BMICalculatorRESTWebService
{

    [ServiceContract]
    public interface IBMICalculatorService
    {

        [OperationContract]
        [WebGet(ResponseFormat = WebMessageFormat.Json, UriTemplate = "/MyBMI?height={height}&weight={weight}")]
        double MyBMI(int height, int weight);

        [OperationContract]
        [WebGet(ResponseFormat = WebMessageFormat.Xml, UriTemplate = "/MyHealth?height={height}&weight={weight}")]
        BMIStructure MyHealth(int height, int weight);
    }


    [DataContract]
    public class BMIStructure
    {
        [DataMember]
        public double bmiValue { get; set; }

        [DataMember]
        public string risk { get; set; }

        [DataMember]
        public string[] externalLinks { get; set; }
    }
}
