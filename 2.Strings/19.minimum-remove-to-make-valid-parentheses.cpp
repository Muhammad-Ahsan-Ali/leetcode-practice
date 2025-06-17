class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        int n = s.length();
        int openCnt = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                openCnt++;
            if (s[i] == ')')
                if (openCnt == 0)
                    s[i] = '*';
                else
                    openCnt--;
        }

        int i = n - 1;
        while (openCnt > 0)
        {
            if (s[i] == '(')
            {
                openCnt--;
                s[i] = '*';
            }
            i--;
        }

        string res = "";

        for (char c : s)
        {
            if (c != '*')
                res += c;
        }
        return res;
    }
};