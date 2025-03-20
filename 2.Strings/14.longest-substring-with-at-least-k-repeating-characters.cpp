class Solution
{
public:
    int longestSubstring(string s, int k)
    {

        int n = s.length();
        int freq[26] = {0};
        int unique = 0;
        int ans = 0;

        for (char c : s)
        {
            if (freq[c - 'a'] == 0)
            {
                unique++;
            }
            freq[c - 'a']++;
        }

        for (int cur_unique = 0; cur_unique <= unique; cur_unique++)
        {
            memset(freq, 0, sizeof(freq));
            int start = 0;
            int end = 0;
            int cnt = 0, count_k = 0;

            while (end < n)
            {
                if (cnt <= cur_unique)
                {
                    int ind = s[end] - 'a';
                    if (freq[ind] == 0)
                    {
                        cnt++;
                    }
                    freq[ind]++;
                    if (freq[ind] == k)
                    {
                        count_k++;
                    }
                    end++;
                }
                else
                {
                    int ind = s[start] - 'a';
                    if (freq[ind] == k)
                    {
                        count_k--;
                    }
                    freq[ind]--;
                    if (freq[ind] == 0)
                    {
                        cnt--;
                    }
                    start++;
                }
                if (cnt == cur_unique && count_k == cur_unique)
                {
                    ans = max(ans, end - start);
                }
            }
        }
        return ans;
    }
};