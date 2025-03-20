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
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *fast = head;
    ListNode *slow = head;
    ListNode *prev;
    int steps = 0;

    while (fast != NULL)
    {
        fast = fast->next;

        steps++;

        if (steps > n)
        {
            prev = slow;
            slow = slow->next;
        }
    }

    if (slow == head)
    {
        return head->next;
    }
    else if (slow == NULL)
    {
        return NULL;
    }
    else
    {
        prev->next = slow->next;
    }
    return head;
}

int main()
{

    return 0;
}