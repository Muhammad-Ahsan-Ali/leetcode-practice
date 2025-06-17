class Solution
{
    string cnvrtToBase(int n, int base)
    {
        string res = "";

        while (n)
        {
            res += n % base;
            n = n / base;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    bool isPalindrome(string temp)
    {
        int l = 0;
        int r = temp.length() - 1;
        while (l < r)
        {
            if (temp[l] != temp[r])
                return false;37
            l++;
            r--;
        }
        return true;
    }

public:
    bool isStrictlyPalindromic(int n)
    {
        for (int i = 2; i <= n - 2; i++)
        {
            if (!isPalindrome(cnvrtToBase(n, i)))
                return false;
        }
        return true;
    }
};