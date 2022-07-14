
#include "stdafx.h"
#include <iostream>
#include <unordered_set>
#include <vector>

class Node
{
public:
    Node(int data) : m_data(data), m_nextNode(nullptr)
    {

    }

    const int m_data;
    Node* m_nextNode;
};

class LinkedList
{
public:
    LinkedList() : m_rootNode(nullptr)
    {}
    void AddNode(int nData);
    void CreateList(const std::vector<int>& dataList);
    void DeleteList();
    Node* DeleteDuplicates();
    Node* DeleteNodeWithData(int data);
    void ReverseLinkedList();
    Node* ReverseListUsingTemp();
    void AlternateReverseList();
    Node* ReverseKNodes(int nNodesCount);
    void DisplayList();
    void SplitList(Node* pRootNode, Node*& pFirstHalf, Node*& pSecondHalf);
    Node* FindCycleNode(Node* pHead);
    Node* MergeKSortedLists(std::vector<Node*> KLists);
    Node* MergeAndSortLinkedLists(Node* pFirstList, Node* pSecondList);
    Node* AddTwoNumbers(Node* pFirstList, Node* pSecondList);
    void RemoveDuplicates();
    void RemoveDuplicatesUnSorted();
    Node* RemoveNthFromEnd(Node* pHead, int nPosition);
    Node* RotateRight(Node* head, int k);
    Node* Partition(Node* head, int value);
    Node* GetHeadNode()
    {
        return m_rootNode;
    }

private:
    void DeleteNodes(Node* pHead);
    Node* ReverseList(Node* prevNode, Node* currNode);

private:
    Node* m_rootNode;
};



static void RunLinkedList()
{
    LinkedList list;
    std::cout << "****Create List***********\n";
    list.CreateList({ 1, 1, 2, 2, 3, 4, 6, 7, 8, 9, 10, 11, 3, 6, 7 });
    list.DisplayList();

    std::cout << "****DeleteDuplicates***********\n";
    list.DeleteDuplicates();
    list.DisplayList();

    std::cout << "****DeleteNodeWithData***********\n";
    list.DeleteNodeWithData(4);
    list.DisplayList();

    std::cout << "****ReverseLinkedList***********\n";
    list.ReverseLinkedList();
    list.DisplayList();

    std::cout << "****ReverseListUsingTemp***********\n";
    list.ReverseListUsingTemp();
    list.DisplayList();

    std::cout << "****AlternateReverseList***********\n";
    list.AlternateReverseList();
    list.DisplayList();

    std::cout << "****ReverseKNodes***********\n";
    list.ReverseKNodes(4);
    list.DisplayList();

    std::cout << "****RemoveDuplicatesUnSorted***********\n";
    list.RemoveDuplicatesUnSorted();
    list.DisplayList();

    std::cout << "****RemoveDuplicates***********\n";
    list.RemoveDuplicates();
    list.DisplayList();
    

    
    /*LinkedList list2;
    list2.CreateList({ 1, 2, 3, 2, 6, 7 });
    list.AddTwoNumbers(list.GetHeadNode(), list2.GetHeadNode());

    list.Partition(list.GetHeadNode(), 2);
    //list.GetHeadNode()->m_nextNode->m_nextNode->m_nextNode->m_nextNode->m_nextNode = list.GetHeadNode()->m_nextNode;
    //list.DisplayList(list.RemoveNthFromEnd(list.GetHeadNode(), 1));
    
    //list.DisplayList(list.ReverseList(NULL, list.GetHeadNode()));
    
    list.AlternateReverseList(list.GetHeadNode());
    //Node* pNode = list.ReverseKNodes(list.GetHeadNode(), 3);
    Node* pFirst = NULL;
    Node* pSecond = NULL;
    //list.SplitList(list.GetHeadNode(), pFirst, pSecond);
    list.DisplayList(list.GetHeadNode());
    //list.DisplayList(pFirst);
    //list.DisplayList(pSecond);
    //list.DeleteNodes(list.GetHeadNode());
    //list.ReverseLinkedList();
    //list.DeleteFromEnd();
    //list.CreateList(6);*/
}