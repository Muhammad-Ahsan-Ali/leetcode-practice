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

ListNode *rotateRight(ListNode *head, int k)
{

    if (head == NULL || head->next == NULL || k == 0)
    {
        return head;
    }
    ListNode *cur = head;

    int length = 0;

    while (cur != NULL)
    {
        cur = cur->next;
        length++;
    }

    k = k % length;

    int rotations = 0;

    while (rotations < k)
    {
        ListNode *cur = head;
        ListNode *prev = cur;

        while (cur != NULL)
        {
            if (cur->next == NULL)
            {
                break;
            }
            prev = cur;
            cur = cur->next;
        }

        if (prev != NULL)
        {
            prev->next = NULL;
            cur->next = head;
            head = cur;
        }

        rotations++;
    }
    return head;
}

int main()
{

    return 0;
}