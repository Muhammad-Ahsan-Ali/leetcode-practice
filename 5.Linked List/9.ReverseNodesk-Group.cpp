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

void sol(int count, ListNode *&cur, ListNode *&start, int k, ListNode *&newHead, int inversions)
{

    if (cur == NULL)
    {
        return;
    }

    if (count == 1)
    {
        start = cur;
    }

    if (count == k)
    {
        ListNode *temp = cur->next;
        cur->next = NULL;
        ListNode *tempCur = reverseList(start);
        inversions++;

        if (inversions == 1)
        {
            newHead = tempCur;
        }

        while (tempCur != NULL)
        {

            if (tempCur->next == NULL)
            {
                break;
            }
            cout << 'did';
            tempCur = tempCur->next;
        }

        tempCur->next = temp;
        sol(1, temp, start, k, newHead, inversions);
        return;
    }

    cur = cur->next;

    sol(count + 1, cur, start, k, newHead, inversions);
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    int length = 0;
    ListNode *cur = head;
    ListNode *newHead = head;

    while (cur != NULL)
    {
        cur = cur->next;
        length++;
    }

    if (k > length || k == 1 || head == NULL)
    {
        return head;
    }

    sol(1, head, head, k, newHead, 0);

    return newHead;
}

// COORECT SOLUTION
ListNode *reverseList(ListNode *head)
{
    ListNode *cur = head;
    ListNode *prev = NULL;
    ListNode *next = NULL;

    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

ListNode *sol(ListNode *cur, int k)
{
    ListNode *start = cur;
    ListNode *prev = NULL;
    int count = 0;

    // First, check if there are k nodes left to reverse
    ListNode *check = cur;
    for (int i = 0; i < k; ++i)
    {
        if (check == NULL)
            return cur; // If less than k nodes, return the current head without reversing
        check = check->next;
    }

    // Reverse the next k nodes
    while (cur != NULL && count < k)
    {
        ListNode *next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
        count++;
    }

    // After reversal, `start` is now the last node in the reversed group
    // Recursively reverse the remaining groups and connect them
    if (cur != NULL)
    {
        start->next = sol(cur, k);
    }

    // `prev` is the new head of the reversed group
    return prev;
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    if (!head || k == 1)
    {
        return head;
    }

    return sol(head, k);
}

int main()
{
    return 0;
}