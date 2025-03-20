class Solution
{
    int kmp(string str, string substr)
    {
        int n = str.length();
        int m = substr.length();
        vector<int> lps(m, 0);

        int j = 1;
        int len = 0;
        while (j < m)
        {
            if (substr[j] == substr[len])
            {
                len++;
                lps[j] = len;
                j++;
            }
            else
            {
                if (len != 0)
                {
                    len = lps[len - 1];
                }
                else
                {
                    lps[j] = 0;
                    j++;
                }
            }
        }

        int i = 0;
        j = 0;

        while (i < n)
        {
            if (str[i] == substr[j])
            {
                i++;
                j++;
            }
            if (j == m)
            {
                return i - j;
            }
            else if (i < n && str[i] != substr[j])
            {
                if (j != 0)
                {
                    j = lps[j - 1];
                }
                else
                {
                    i++;
                }
            }
        }
        return -1;
    }

public:
    int strStr(string haystack, string needle) { return kmp(haystack, needle); }
};
