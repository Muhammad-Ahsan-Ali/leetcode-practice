class Solution
{
public:
    string removeOuterParentheses(string s)
    {

        string output = "";
        int cnt = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                cnt++;
            }
            while (cnt != 0)
            {
                i++;
                if (s[i] == '(')
                {
                    cnt++;
                }
                else
                {
                    cnt--;
                }
                if (cnt != 0)
                {
                    output += s[i];
                }
            }
        }
        return output;
    }
};

// correct sol

class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        string output = "";
        int cnt = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                // Only add if it's not the outermost '('
                if (cnt > 0)
                {
                    output += s[i];
                }
                cnt++;
            }
            else
            {
                cnt--;
                // Only add if it's not the outermost ')'
                if (cnt > 0)
                {
                    output += s[i];
                }
            }
        }
        return output;
    }
};
