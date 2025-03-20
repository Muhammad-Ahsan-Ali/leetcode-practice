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

bool hasCycle(ListNode *head)
{
    ListNode *fastCur = head;
    ListNode *slowCur = head;
    while (fastCur != NULL)
    {
        slowCur = slowCur->next;

        if (fastCur->next == NULL || fastCur->next->next == NULL)
        {
            return false;
        }

        fastCur = fastCur->next->next;

        if (slowCur == fastCur)
        {
            return true;
        }
    }
    return false;
}

int main()
{

    return 0;
}