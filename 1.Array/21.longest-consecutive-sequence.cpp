class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }

        unordered_set<int> st;
        int longest = 1;

        for (int i = 0; i < n; i++)
        {
            st.insert(a[i]);
        }

        for (int it : st)
        {
            if (st.find(it - 1) == st.end())
            {
                int cnt = 1;
                x = it;
                while (st.find(x + 1) != st.end())
                {
                    cnt++;
                    x++;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};