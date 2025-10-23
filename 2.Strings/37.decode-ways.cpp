class Solution
{
private:
    bool consecutiveZero(string s)
    {
        for (int i = 1; i < s.length(); i++)
            if (s[i] == '0' && s[i - 1] == '0') // keep only invalid "00"
                return 1;
        return 0;
    }

public:
    int numDecodings(string s)
    {
        int n = s.length();

        if (s[0] == '0' || consecutiveZero(s))
            return 0;

        int cnt1 = 1, cnt2 = 0;

        for (int i = 1; i < n; i++)
        {
            int tcnt2 = cnt2;
            cnt2 = 0;

            int two = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if (two >= 10 && two <= 26)
                cnt2 = cnt1;

            if (s[i] == '0')
                cnt1 = 0;
            else
                cnt1 += tcnt2;
        }

        return cnt1 + cnt2;
    }
};

// ideal

class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.size();
        if (n == 0 || s[0] == '0')
            return 0;

        int prev = 1; // dp[i-2]
        int curr = 1; // dp[i-1]

        for (int i = 1; i < n; i++)
        {
            int temp = 0;

            // Check single digit
            if (s[i] != '0')
                temp += curr;

            // Check two digits
            int two = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if (two >= 10 && two <= 26)
                temp += prev;

            prev = curr;
            curr = temp;
        }

        return curr;
    }
};
