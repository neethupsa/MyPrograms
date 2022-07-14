#include "stdafx.h"
#include "LinkedList.h"

void LinkedList::AddNode(int nData)
{
    if (!m_rootNode) {
        m_rootNode = new Node(nData);
        return;
    }

    Node* temp = m_rootNode;
    while (temp)
    {
        if (temp->m_nextNode == nullptr) {
            temp->m_nextNode = new Node(nData);
            return;
        }
        temp = temp->m_nextNode;
    }
}

void LinkedList::CreateList(const std::vector<int>& dataList)
{
    for (auto const& data : dataList) {
        AddNode(data);
    }
}

void LinkedList::DeleteList()
{
    DeleteNodes(m_rootNode);
    m_rootNode = nullptr;
}

void LinkedList::DeleteNodes(Node* pHead)
{
    if (pHead && pHead->m_nextNode) {
        DeleteNodes(pHead->m_nextNode);
    }
    delete pHead;
    pHead = nullptr;
}

/*
Given a sorted linked list, delete all nodes that have duplicate numbers,
leaving only distinct numbers from the original list.

Example 1:
Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:
Input: 1->1->1->2->3
Output: 2->3
*/
Node* LinkedList::DeleteDuplicates()
{
    //head is 1->1->1->2->3
    Node* prev = new Node(0);
    prev->m_nextNode = m_rootNode;
    //0->1->1->1->2->3
    Node* curr = prev;

    while (curr->m_nextNode && curr->m_nextNode->m_nextNode)
    {
        if (curr->m_nextNode->m_data == curr->m_nextNode->m_nextNode->m_data)
        {
            auto const dupVal = curr->m_nextNode->m_data;
            while (curr->m_nextNode && curr->m_nextNode->m_data == dupVal)
            {
                auto const tmpNode = curr->m_nextNode;
                curr->m_nextNode = curr->m_nextNode->m_nextNode;
                delete tmpNode;
            }
        }
        else
        {
            curr = curr->m_nextNode;
        }
    }
    m_rootNode = prev->m_nextNode;
    return m_rootNode;
}

Node* LinkedList::DeleteNodeWithData(int data)
{
    //head is 1->1->1->2->3
    Node* prevNode = new Node(0);
    prevNode->m_nextNode = m_rootNode;
    //0->1->1->1->2->3
    Node* currNode = prevNode;

    while (currNode->m_nextNode)
    {
        if (currNode->m_nextNode->m_data == data) {
            auto const tmpNode = currNode->m_nextNode;
            currNode->m_nextNode = currNode->m_nextNode->m_nextNode;
            delete tmpNode;
        }
        else {
            currNode = currNode->m_nextNode;
        }
    }
    m_rootNode = prevNode->m_nextNode;
    return m_rootNode;
}

Node* LinkedList::ReverseList(Node* prevNode, Node* currNode)
{
    Node* pHeadNode = nullptr;
    if (currNode->m_nextNode != nullptr) {
        pHeadNode = ReverseList(currNode, currNode->m_nextNode);
    }
    else {
        pHeadNode = currNode;
    }
    currNode->m_nextNode = prevNode;
    return pHeadNode;
}

Node* LinkedList::ReverseListUsingTemp()
{
    if (m_rootNode == nullptr) {
        return nullptr;
    }

    Node* pPrev = nullptr;
    Node* pCurr = m_rootNode;
    Node* pNext = nullptr;

    while (pCurr)
    {
        pNext = pCurr->m_nextNode;
        pCurr->m_nextNode = pPrev;
        pPrev = pCurr;
        pCurr = pNext;
    }

    m_rootNode = pPrev;
    return pPrev;
}


void LinkedList::ReverseLinkedList()
{
    Node* temp = m_rootNode;
    m_rootNode = ReverseList(nullptr, m_rootNode);
}

/*
Input List:  1->2->3->4->5->6
Output List: 1->3->5->6->4->2
*/
void LinkedList::AlternateReverseList()
{
    if (m_rootNode == nullptr) {
        return;
    }
    Node* pCurrNode = m_rootNode;
    Node* pEvenList = nullptr;
    while (pCurrNode->m_nextNode)
    {
        //Take even nodes.
        Node* pTemp = pCurrNode->m_nextNode;
        if (pCurrNode->m_nextNode->m_nextNode)
        {
            //Point to next odd node.
            pCurrNode->m_nextNode = pCurrNode->m_nextNode->m_nextNode;
            pTemp->m_nextNode = pEvenList;
            pEvenList = pTemp;
        }
        else
        {
            //last even node.
            pTemp->m_nextNode = pEvenList;
            pEvenList = pTemp;
            break;
        }
        pCurrNode = pCurrNode->m_nextNode;
    }
    pCurrNode->m_nextNode = pEvenList;
}

//Input: 1->2->3->4->5->6->7->8->9->10->NULL  k = 3
//Output : 3->2->1->4->5->6->7->8->9->10->NULL
//
//Input : 10->18->20->25->35->NULL  k = 2
//Output : 18->10->20->25->35->NULL
Node* LinkedList::ReverseKNodes(int nNodesCount)
{
    Node* current = m_rootNode;
    Node* next = nullptr;
    Node* prev = nullptr;
    int count = 0;

    /*reverse first k nodes of the linked list */
    while (current && count < nNodesCount)
    {
        next = current->m_nextNode;
        current->m_nextNode = prev;
        prev = current;
        current = next;
        count++;
    }

    // join both parts of the linked list
    // traverse the list until NULL is not found
    // Node* jointNode = current;
    m_rootNode = prev;
    while (prev->m_nextNode) {
        prev = prev->m_nextNode;
    }
    prev->m_nextNode = current;

    /* prev is new head of the input list */
    return m_rootNode;
}

/* Function to remove duplicates from an unsorted linked list 
Input : 12->11->12->21->41->43->21
Output - 12->11->21->41->43 */
void LinkedList::RemoveDuplicatesUnSorted()
{
    // Hash to store seen values
    std::unordered_set<int> seen;

    /* Pick elements one by one */
    Node* pCurrent = m_rootNode;
    Node* pPrev = nullptr;
    while (pCurrent)
    {
        // If current value is seen before
        if (seen.find(pCurrent->m_data) != seen.end())
        {
            pPrev->m_nextNode = pCurrent->m_nextNode;
            delete pCurrent;
        }
        else
        {
            seen.insert(pCurrent->m_data);
            pPrev = pCurrent;
        }
        pCurrent = pPrev->m_nextNode;
    }
}

/* Function to remove duplicates from a sorted linked list
Input : 11->12->12->21->41->43->43
Output - 11->12->21->41->43 */
void LinkedList::RemoveDuplicates()
{
    Node* pCurrent = m_rootNode;
    if (!pCurrent) {
        return;
    }
    /* Traverse the list till last node */
    while (pCurrent->m_nextNode)
    {
        /* Compare current node with next node */
        if (pCurrent->m_data == pCurrent->m_nextNode->m_data)
        {
            Node* pTemp = pCurrent->m_nextNode->m_nextNode;
            delete pCurrent->m_nextNode;
            pCurrent->m_nextNode = pTemp;
        }
        else
        {
            pCurrent = pCurrent->m_nextNode;
        }
    }
}


Node* LinkedList::FindCycleNode(Node* pHead)
{
    if (pHead == nullptr)
    {
        return pHead;
    }

    Node* pSlow = pHead;
    Node* pFast = pHead;

    while (pSlow && pFast && pFast->m_nextNode)
    {
        pSlow = pSlow->m_nextNode;
        pFast = pFast->m_nextNode->m_nextNode;

        if (pSlow == pFast)
        {
            break;
        }
    }

    if (pSlow == nullptr || pFast == nullptr || pSlow != pFast)
    {
        return nullptr;
    }

    pSlow = pHead;

    while (pSlow != pFast)
    {
        pSlow = pSlow->m_nextNode;
        pFast = pFast->m_nextNode;
    }
    return pSlow;
}

void LinkedList::SplitList(Node* pRootNode, Node*& pFirstHalf, Node*& pSecondHalf)
{
    if (pRootNode == nullptr)
    {
        return;
    }

    Node* pFirst = pRootNode;
    Node* pSecond = pRootNode;

    while (pFirst->m_nextNode != nullptr && pFirst->m_nextNode->m_nextNode != nullptr)
    {
        pFirst = pFirst->m_nextNode->m_nextNode;
        pSecond = pSecond->m_nextNode;
    }

    if (pFirst->m_nextNode && pFirst->m_nextNode->m_nextNode == nullptr)
    {
        pFirst = pFirst->m_nextNode;
    }

    pFirstHalf = pRootNode;
    if (pRootNode->m_nextNode != nullptr)
    {
        pSecondHalf = pSecond->m_nextNode;
        pSecond->m_nextNode = nullptr;
    }
}

Node* LinkedList::MergeKSortedLists(std::vector<Node*> KLists)
{
    int nLength = KLists.size();
    if (nLength > 0)
    {
        nLength -= 1;
    }
    else
    {
        return nullptr;
    }
    int nLeft = 0;
    int nRight = nLength;
    while (nLength > 0)
    {
        nLeft = 0;
        nRight = nLength;

        while (nLeft < nRight)
        {
            KLists[nLeft] = MergeAndSortLinkedLists(KLists[nLeft++], KLists[nRight--]);

            if (nLeft >= nRight)
            {
                nLength = nRight;
            }
        }
    }
    return KLists[0];
}

Node* LinkedList::MergeAndSortLinkedLists(Node* pFirstList, Node* pSecondList)
{
    Node* pResultList = nullptr;
    if (pFirstList == nullptr)
    {
        return pSecondList;
    }

    if (pSecondList == nullptr)
    {
        return pFirstList;
    }

    if (pFirstList->m_data <= pSecondList->m_data)
    {
        pResultList = pFirstList;
        pResultList->m_nextNode = MergeAndSortLinkedLists(pFirstList->m_nextNode, pSecondList);
    }
    else
    {
        pResultList = pSecondList;
        pResultList->m_nextNode = MergeAndSortLinkedLists(pFirstList, pSecondList->m_nextNode);
    }

    return pResultList;
}

Node* LinkedList::AddTwoNumbers(Node* pFirstList, Node* pSecondList)
{
    Node* pResultList = nullptr;
    Node* pPrev = nullptr;
    Node* pTemp = nullptr;
    int nCarry = 0;
    int nSum = 0;

    while (pFirstList || pSecondList)
    {
        nSum = nCarry + (pFirstList ? pFirstList->m_data : 0) + (pSecondList ? pSecondList->m_data : 0);
        nCarry = (nSum >= 10) ? 1 : 0;
        nSum = nSum % 10;

        pTemp = new Node(nSum);
        if (pResultList == nullptr)
        {
            pResultList = pTemp;
        }
        else
        {
            pPrev->m_nextNode = pTemp;
        }

        pPrev = pTemp;

        if (pFirstList)
        {
            pFirstList = pFirstList->m_nextNode;
        }

        if (pSecondList)
        {
            pSecondList = pSecondList->m_nextNode;
        }
    }

    if (nCarry > 0)
    {
        pTemp->m_nextNode = new Node(nCarry);
    }

    return pResultList;
}

Node* LinkedList::RemoveNthFromEnd(Node* pHead, int nPosition)
{
    if (!pHead)
    {
        return pHead;
    }
    Node* pFirst = pHead;
    Node* pSecond = pHead;
    Node* pTemp = nullptr;
    for (int nIndex = 0; nIndex < nPosition; ++nIndex)
    {
        pFirst = pFirst->m_nextNode;
    }

    if (pFirst == nullptr)
    {
        pTemp = pHead;
        pHead = pHead->m_nextNode;
        delete pTemp;
    }
    else
    {
        while (pFirst->m_nextNode)
        {
            pFirst = pFirst->m_nextNode;
            pSecond = pSecond->m_nextNode;
        }
        pTemp = pSecond->m_nextNode;
        pSecond->m_nextNode = pTemp->m_nextNode;
        delete pTemp;
    }
    return pHead;
}

/*
Given a linked list, rotate the list to the right by k places, where k is non-negative.
Example 1:
Input: 1->2->3->4->5->nullptr, k = 2
Output: 4->5->1->2->3->nullptr
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->nullptr
rotate 2 steps to the right: 4->5->1->2->3->nullptr
Example 2:
Input: 0->1->2->nullptr, k = 4
Output: 2->0->1->nullptr
Explanation:
rotate 1 steps to the right: 2->0->1->nullptr
rotate 2 steps to the right: 1->2->0->nullptr
rotate 3 steps to the right: 0->1->2->nullptr
rotate 4 steps to the right: 2->0->1->nullptr
*/
Node* RotateRight(Node* pHead, int rotTimes)
{
    if (rotTimes <= 0 || !pHead || !pHead->m_nextNode)
    {
        return pHead;
    }

    Node* curr = pHead;
    int Length = 0;
    while (curr)
    {
        Length++;
        curr = curr->m_nextNode;
    }

    (rotTimes > Length) ? rotTimes = rotTimes % Length : rotTimes;
    Node* tmp = nullptr;
    while (rotTimes > 0)
    {
        curr = pHead;
        while (curr && curr->m_nextNode)
        {
            if (curr->m_nextNode->m_nextNode == nullptr)
            {
                tmp = curr->m_nextNode;
                curr->m_nextNode = curr->m_nextNode->m_nextNode;
                tmp->m_nextNode = pHead;
                pHead = tmp;
            }
            curr = curr->m_nextNode;
        }
        rotTimes--;
    }
    return pHead;
}

/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:
Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
*/
Node* LinkedList::Partition(Node* head, int value)
{
    if (!head)
    {
        return head;
    }
    Node* newHead = nullptr;
    Node* prev = nullptr;
    Node* after = nullptr;
    Node* tmp = nullptr;

    while (head)
    {
        if (head->m_data < value)
        {
            if (!newHead)
            {
                newHead = head;
            }
            prev = head;
            head = head->m_nextNode;
        }
        else
        {
            if (!after)
            {
                after = head;
                tmp = after;
                head = head->m_nextNode;
                tmp->m_nextNode = nullptr;
            }
            else
            {
                tmp->m_nextNode = head;
                head = head->m_nextNode;
                tmp = tmp->m_nextNode;
                tmp->m_nextNode = nullptr;
            }
            if (prev)
            {
                prev->m_nextNode = head;
            }
        }
    }
    (prev) ? (prev->m_nextNode ? prev->m_nextNode->m_nextNode = after : prev->m_nextNode = after) : newHead = after;
    return newHead;
}

void LinkedList::DisplayList()
{
    if (!m_rootNode)
    {
        return;
    }
    Node* pTemp = m_rootNode;
    while (pTemp)
    {
        std::cout << pTemp->m_data << "->";
        pTemp = pTemp->m_nextNode;
    }
    std::cout << "\n";
}