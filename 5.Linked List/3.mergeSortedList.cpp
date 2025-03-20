#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *dummy = new ListNode(0);
    ListNode *temp = dummy;
    ListNode *cur1 = list1;
    ListNode *cur2 = list2;

    while (cur1 != NULL && cur2 != NULL)
    {
        if (cur1->val > cur2->val)
        {
            temp->next = cur2;
            cur2 = cur2->next;
            temp = temp->next;
        }
        else
        {
            temp->next = cur1;
            cur1 = cur1->next;
            temp = temp->next;
        }
    }

    while (cur1 != NULL)
    {

        temp->next = cur1;
        cur1 = cur1->next;
        temp = temp->next;
    }

    while (cur2 != NULL)
    {

        temp->next = cur2;
        cur2 = cur2->next;
        temp = temp->next;
    }
    ListNode *mergedList = dummy->next;
    temp->next = NULL;
    return mergedList;
}

int main()
{

    return 0;
}