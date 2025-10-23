class Solution
{
private:
    string stringAdd(string a, string b)
    {
        string ans;
        int n = a.size(), m = b.size();
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0;
        int i = 0;

        for (; i < min(n, m); i++)
        {
            int sum = (a[i] - '0') + (b[i] - '0') + carry;
            ans += (char)(sum % 10 + '0');
            carry = sum / 10;
        }

        for (; i < n; i++)
        {
            int sum = (a[i] - '0') + carry;
            ans += (char)(sum % 10 + '0');
            carry = sum / 10;
        }

        for (; i < m; i++)
        {
            int sum = (b[i] - '0') + carry;
            ans += (char)(sum % 10 + '0');
            carry = sum / 10;
        }

        if (carry)
            ans += (char)(carry + '0');

        reverse(ans.begin(), ans.end());
        return ans;
    }

    bool isValidNumber(string num)
    {
        return !(num.size() > 1 && num[0] == '0');
    }

    bool backtrack(string num, int start, string num1, string num2)
    {
        if (start == num.size())
            return 1;

        string sum = stringAdd(num1, num2);
        if (start + sum.size() > num.size() ||
            num.substr(start, sum.size()) != sum)
            return false;

        return backtrack(num, start + sum.size(), num2, sum);
    }

public:
    bool isAdditiveNumber(string num)
    {
        int n = num.size();

        for (int i = 1; i < n; i++)
            for (int j = i + 1; j < n; j++)
            {
                string num1 = num.substr(0, i);
                string num2 = num.substr(i, j - i);

                if (!isValidNumber(num1) || !isValidNumber(num2))
                    continue;

                if (backtrack(num, j, num1, num2))
                    return true;
            }

        return false;
    }
};

// optimization

class Solution
{
private:
    string stringAdd(string a, string b)
    {
        string ans;
        int n = a.size(), m = b.size();
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int carry = 0, i = 0;
        for (; i < min(n, m); i++)
        {
            int sum = (a[i] - '0') + (b[i] - '0') + carry;
            ans += (char)(sum % 10 + '0');
            carry = sum / 10;
        }
        for (; i < n; i++)
        {
            int sum = (a[i] - '0') + carry;
            ans += (char)(sum % 10 + '0');
            carry = sum / 10;
        }
        for (; i < m; i++)
        {
            int sum = (b[i] - '0') + carry;
            ans += (char)(sum % 10 + '0');
            carry = sum / 10;
        }
        if (carry)
            ans += (char)(carry + '0');

        reverse(ans.begin(), ans.end());
        return ans;
    }

    bool isValidNumber(string num)
    {
        return !(num.size() > 1 && num[0] == '0');
    }

    bool checkSequence(string num, string num1, string num2, int start)
    {
        while (start < num.size())
        {
            string sum = stringAdd(num1, num2);

            if (start + sum.size() > num.size() || num.substr(start, sum.size()) != sum)
                return false;

            num1 = num2;
            num2 = sum;
            start += sum.size();
        }
        return true;
    }

public:
    bool isAdditiveNumber(string num)
    {
        int n = num.size();

        for (int i = 1; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                string num1 = num.substr(0, i);
                string num2 = num.substr(i, j - i);

                if (!isValidNumber(num1) || !isValidNumber(num2))
                    continue;

                if (checkSequence(num, num1, num2, j))
                    return true;
            }
        }
        return false;
    }
};