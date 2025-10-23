class Solution
{
private:
    vector<int> pre;
    int cal = 0;
    bool check(int n)
    {
        string s = to_string(n);
        bool hasChange = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '3' || s[i] == '4' || s[i] == '7')
                return false;
            if (s[i] == '2' || s[i] == '5' || s[i] == '9' || s[i] == '6')
                hasChange = 1;
        }
        return hasChange;
    }

public:
    Solution() : pre(1e4 + 1, 0) {}
    int rotatedDigits(int n)
    {

        if (!cal)
        {
            pre[0] = 0;
            for (int i = 1; i < 1e4 + 1; i++)
            {
                if (check(i))
                    pre[i] = pre[i - 1] + 1;
                else
                    pre[i] = pre[i - 1];
            }
            cal = 1;
        }

        return pre[n];
    }
};

// chat gpt
class Solution
{
private:
    bool check(int n)
    {
        bool has_change = false;
        for (char c : to_string(n))
        {
            if (c == '3' || c == '4' || c == '7')
                return false;
            if (c == '2' || c == '5' || c == '6' || c == '9')
                has_change = true;
        }
        return has_change;
    }

public:
    int rotatedDigits(int n)
    {
        static vector<int> pre(1e4 + 1, -1);
        static bool computed = false;

        if (!computed)
        {
            pre[0] = 0;
            for (int i = 1; i <= 1e4; ++i)
                pre[i] = pre[i - 1] + (check(i) ? 1 : 0);
            computed = true;
        }

        return pre[n];
    }
};

// digit dp 0( 80)

class Solution
{

private:
    string num;

    int dp[5][2][2][2];

    int cal(int ind, bool tight, bool lz, bool changeAble)
    {
        if (ind >= num.size())
            return !lz && changeAble;

        if (dp[ind][tight][lz][changeAble] != -1)
            return dp[ind][tight][lz][changeAble];

        int limit = tight ? num[ind] - '0' : 9;
        int ans = 0;
        for (int i = 0; i <= limit; i++)
        {
            if (i == 3 || i == 7 || i == 4)
                continue;
            bool nt = tight && i == limit;
            bool nlz = lz && i == 0;
            bool nc = changeAble || (i == 2 || i == 5 || i == 6 || i == 9);
            ans += cal(ind + 1, nt, nlz, nc);
        }
        return dp[ind][tight][lz][changeAble] = ans;
    }

public:
    int rotatedDigits(int n)
    {
        memset(dp, -1, sizeof(dp));
        num = to_string(n);
        return cal(0, 1, 1, 0);
    }
};