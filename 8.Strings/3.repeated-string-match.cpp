class Solution
{
    bool kmp(string str, string sub)
    {
        int n = sub.length();
        int m = str.length();
        vector<int> lps(n, 0);

        lps[0] = 0;
        int i = 1;
        int len = 0;

        while (i < n)
        {
            if (sub[i] == sub[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len != 0)
                {
                    len = lps[len - 1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        i = 0;
        int j = 0;

        while (i < m)
        {
            if (str[i] == sub[j])
            {
                i++;
                j++;
            }

            if (j == n)
            {
                return true;
            }
            else if (i < m && str[i] != sub[j])
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
    int repeatedStringMatch(string a, string b)
    {
        int n = b.length() / a.length();

        string res = "";
        for (int i = 0; i < n; i++)
        {
            res += a;
        }

        int i = 0;
        while (i <= 2)
        {
            if (kmp(res, b))
            {
                return n;
            }
            res += a;
            i++;
            n++;
        }

        return -1;
    }
};