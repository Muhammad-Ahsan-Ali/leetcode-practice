#include <iostream>
#include <string.h>
using namespace std;
bool palindrome(string s)
{
    bool isPalindrome = false;
    int len = s.length();
    char arr[len];
    int j = 0;

    for (int i = 0; i < len; i++)
    {
        // Check if the character is a letter
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            arr[j] = tolower(s[i]); // Copy the alphabetic character to arr
            j++;                    // Move to the next position in arr
        }
    }

    for (int i = 0; i < j - i; i++)
    {
        // cout << arr[i];
        if (arr[i] == arr[j - 1 - i])
        {
            isPalindrome = true;
        }
        else
        {
            return false;
        }
    }
    return isPalindrome;
}

int main()
{

    string s = "A man, a plan, a canal : Panama";
    if (palindrome(s))
    {
        cout << " palindrome()";
    }

    return 0;
}