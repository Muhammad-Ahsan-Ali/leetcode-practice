
bool palindrome(string s)
{
    int len = s.length();
    for (int i = 0; i < len / 2; i++)
    {
        if (s[i] != s[len - 1 - i])
        {
            return false;
        }
    }

    return true;
}

string longestPalindrome(string s)
{
    int len = s.length();
    string returningString = "";
    int maxLenPalindrome = 0;

    for (int i = 0; i < len; i++)
    {
        for (int j = 1; j <= len - i; j++)
        {

            if (palindrome(s.substr(i, j)))
            {
                // cout << "ispalindrome" << i << j << s.substr(i, j) << endl;
                if (maxLenPalindrome < j)
                {
                    maxLenPalindrome = j;
                    returningString = s.substr(i, j);
                }
            }
        }
    }

    return returningString;
}

// dp appraoch...................................................................................

string longestPalindrome(string s)
{
    int len = s.length();

    if (len <= 1)
    {
        return s;
    }

    // Dynamic programming table to store palindrome info
    bool dp[len][len] = {false}; // Assuming max length of string is 1000
    int max_len = 1;
    int start = 0;

    // Every single character is a palindrome
    for (int i = 0; i < len; ++i)
    {
        dp[i][i] = true;
    }

    // Check for substrings of length 2
    for (int i = 0; i < len - 1; ++i)
    {
        if (s[i] == s[i + 1])
        {
            dp[i][i + 1] = true;
            start = i;
            max_len = 2;
        }
    }

    // Check for substrings longer than 2
    for (int curr_len = 3; curr_len <= len; ++curr_len)
    {
        for (int i = 0; i + curr_len - 1 < len; ++i)
        {
            int j = i + curr_len - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1])
            {
                dp[i][j] = true;
                start = i;
                max_len = curr_len;
            }
        }
    }

    // Return the longest palindrome substring using string::substr
    return s.substr(start, max_len);
}

// on2  sc o1 method //...........................................................

class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.empty())
        {
            return "";
        }

        int start = 0;
        int end = 0;

        for (int i = 0; i < s.length(); i++)
        {
            int odd = expandAroundCenter(s, i, i);
            int even = expandAroundCenter(s, i, i + 1);
            int max_len = max(odd, even);

            if (max_len > end - start)
            {
                start = i - (max_len - 1) / 2;
                end = i + max_len / 2;
            }

        }

        return s.substr(start, end - start + 1);
    }

private:
    int expandAroundCenter(string s, int left, int right)
    {
        while (left >= 0 && right < s.length() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return right - left - 1;
    }
};