
class Solution
{
public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *lst2Ed = list2;

        while (lst2Ed->next != nullptr)
            lst2Ed = lst2Ed->next;

        int cnt = 0;

        ListNode *cur = list1;

        while (cur && cnt < a - 1)
        {
            cur = cur->next;
            cnt++;
        }

        ListNode *tmp = cur;
        cur = cur->next;
        tmp->next = list2;
        while (cur && cnt < b - 1)
        {
            cur = cur->next;
            cnt++;
        }

        if (cur)
            lst2Ed->next = cur->next;

        return list1;
    }
};
