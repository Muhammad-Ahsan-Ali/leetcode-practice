class Solution
{
public:
    int longestSubsequence(string s, int k)
    {
        long long pow = 1;
        int len = 0;

        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == '0')
                len++;
            else
            {
                if (pow <= k)
                {
                    k -= pow;
                    len++;
                }
            }
            if (pow <= k)
                pow <<= 1;
        }
        return len;
    }
};