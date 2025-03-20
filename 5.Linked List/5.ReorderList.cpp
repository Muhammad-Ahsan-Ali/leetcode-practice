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

ListNode *reverseList(ListNode *head)
{

    ListNode *cur = head;
    ListNode *prev;
    ListNode *next;
    prev = NULL;

    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
    return head;
}

void reorderList(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;

    while (fast != NULL)
    {

        if (fast->next == NULL)
        {
            break;
        }

        fast = fast->next->next;
        slow = slow->next;
    }

    ListNode *rvrsdLst = reverseList(slow->next);
    slow->next = NULL;

    ListNode *cur = head;
    ListNode *temp;
    ListNode *lstTemp;

    while (rvrsdLst != NULL)
    {
        temp = cur->next;
        cur->next = rvrsdLst;
        cur = temp;
        lstTemp = rvrsdLst->next;
        rvrsdLst->next = temp;
        rvrsdLst = lstTemp;
    }
}

int main()
{

    return 0;
}