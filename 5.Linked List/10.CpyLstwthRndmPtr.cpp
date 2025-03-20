#include <iostream>
#include <map>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomList(Node *head)
{
    Node *cur = head;

    if (!head)
    {
        return NULL;
    }

    Node *dummyHead = new Node(0);

    Node *temp = dummyHead;
    map<int, int> lstMap;
    int index = 1;

    while (cur != NULL)
    {
        Node *newLstNode = new Node(cur->val);

        int index2 = 1;

        Node *tempCur = head;

        while (tempCur != cur->random)
        {
            tempCur = tempCur->next;
            index2++;
        }

        lstMap.insert({index, index2});

        index++;
        temp->next = newLstNode;
        temp = temp->next;
        cur = cur->next;
    }

    temp->next = NULL;

    Node *newLstcur = dummyHead->next;
    Node *newLstcur2 = dummyHead->next;

    for (const auto &pair : lstMap)
    {
        newLstcur = dummyHead->next;
        int index1 = 1;
        int index2 = 1;

        while (index1 != pair.first)
        {
            newLstcur = newLstcur->next;
            index1++;
        }

        newLstcur2 = dummyHead->next;

        while (index2 != pair.second)
        {
            newLstcur2 = newLstcur2->next;
            index2++;
        }

        newLstcur->random = newLstcur2;
    }

    return dummyHead->next;
}

int main()
{
    return 0;
}