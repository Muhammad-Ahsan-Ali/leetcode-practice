#include <iostream>
using namespace std;

int countSubstrings(string s)
{
    int len = s.length();
    int numberOfPalindromicSubstrings = 0;

    if (len <= 1)
    {
        return len;
    }

    // Dynamic programming table to store palindrome info
    bool dp[len][len] = {false}; // Assuming max length of string is 1000

    // Every single character is a palindrome
    for (int i = 0; i < len; ++i)
    {
        dp[i][i] = true;
        numberOfPalindromicSubstrings++;
    }

    // Check for substrings of length 2
    for (int i = 0; i < len - 1; ++i)
    {
        if (s[i] == s[i + 1])
        {
            dp[i][i + 1] = true;
            numberOfPalindromicSubstrings++;
        }
    }

    // Check for substrings longer than 2
    for (int curr_len = 3; curr_len <= len; ++curr_len)
    {
        for (int i = 0; i <= len - curr_len; ++i)
        {
            int j = i + curr_len - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1])
            {
                dp[i][j] = true;
                numberOfPalindromicSubstrings++;
            }
        }
    }

    // Return the longest palindrome substring using string::substr
    return numberOfPalindromicSubstrings;
}

int main()
{
    string s = "9999900000";

    cout << "longestone " << countSubstrings(s);

    return 0;
}