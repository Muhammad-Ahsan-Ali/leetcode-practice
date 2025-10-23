class Solution
{
public:
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        unordered_map<int, ListNode *> mp;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        int prefix = 0;
        ListNode *cur = dummy;

        while (cur)
        {
            prefix += cur->val;
            mp[prefix] = cur;
            cur = cur->next;
        }

        prefix = 0;
        cur = dummy;
        while (cur)
        {
            prefix += cur->val;
            cur->next = mp[prefix]->next;
            cur = cur->next;
        }

        return dummy->next;
    }
};
