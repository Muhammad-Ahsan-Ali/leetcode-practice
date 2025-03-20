class Solution
{
private:
    bool kmp(string str, string substr)
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
                return true;
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
        return false;
    }

public:
    bool rotateString(string s, string goal)
    {
        string conc_str = s + s;
        return kmp(conc_str, goal);
    }
};