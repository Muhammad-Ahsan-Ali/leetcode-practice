// my code

class Solution
{
public:
    string decodeString(string s)
    {
        int n = s.length();
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            if (isdigit(s[i]))
            {
                int j = i + 2;
                int cnt = 1;
                while (cnt != 0 && j < n)
                {
                    j++;
                    if (s[j] == '[')
                        cnt++;
                    if (s[j] == ']')
                        cnt--;
                }

                int k = 0;
                while (i < n && isdigit(s[i]))
                {
                    k = k * 10 + (s[i] - '0');
                    i++;
                }

                string temp = decodeString(s.substr(i + 1, j - (i + 1)));
                for (int l = 0; l < k; l++)
                    ans += temp;
                i = j;
            }
            else
            {
                if (s[i] != ']')
                    ans += s[i];
            }
        }
        return ans;
    }
};

// more intuitive

class Solution
{
public:
    string decodeString(string &s, int &i)
    {
        string result = "";
        while (i < s.size() && s[i] != ']')
        {
            if (isdigit(s[i]))
            {
                int k = 0;
                while (i < s.size() && isdigit(s[i]))
                {
                    k = k * 10 + (s[i] - '0');
                    i++;
                }
                i++; // skip '['
                string decoded = decodeString(s, i);
                i++; // skip ']'
                while (k-- > 0)
                    result += decoded;
            }
            else
            {
                result += s[i++];
            }
        }
        return result;
    }

    string decodeString(string s)
    {
        int i = 0;
        return decodeString(s, i);
    }
};
