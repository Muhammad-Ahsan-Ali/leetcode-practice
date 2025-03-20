

// soltion

class Solution
{
public:
    string shortestPalindrome(string s)
    {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string temp = s + '-' + rev_s;

        int n = temp.length();
        vector<int> lps(n, 0);

        int i = 1;
        int len = 0;
        while (i < n)
        {
            if (temp[i] == temp[len])
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

        int LPS = lps[n - 1];

        string output = rev_s.substr(0, s.length() - LPS) + s;

        return output;
    }
};
