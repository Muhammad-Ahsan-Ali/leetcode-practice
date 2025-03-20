class Solution
{
public:
    string countAndSay(int n)
    {
        string prev = "1";

        for (int i = 1; i < n; i++)
        {
            string str = prev;
            string res = "";

            for (int i = 0; i < str.length(); i++)
            {
                int cnt = 1;
                char temp = str[i];
                while (str[i] == str[i + 1] && i < str.length() - 1)
                {
                    cnt++;
                    i++;
                }
                res += to_string(cnt) + string(1, temp);
            }
            prev = res;
        }
        return prev;
    }
};
