class Solution
{
public:
    int myAtoi(string s)
    {
        int i = 0;

        long ans = 0;
        int sign = 1;

        while (i < s.length() && s[i] == ' ')
            i++;

        if (i == s.size())
            return 0;

        if (s[i] == '-')
        {
            sign = -1;
            i++;
        }
        else if (s[i] == '+')
            i++;

        while (i < s.length() && isdigit(s[i]))
        {
            ans = ans * 10 + (s[i] - '0');

            if (ans * sign >= INT_MAX)
                return INT_MAX;
            if (ans * sign <= INT_MIN)
                return INT_MIN;

            i++;
        }

        return (int)(ans * sign);
    }
};