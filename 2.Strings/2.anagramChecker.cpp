#include <iostream>
#include <string.h>
using namespace std;
bool anagram(string s, string t)
{
    bool isAnagram = false;
    int lenS = s.length();
    int lenT = t.length();
    int max = 0;
    int hash[60] = {0};
    if (lenS == 1)
    {
        return true;
    }
    if (lenS == lenT)
    {
        for (int i = 0; i < lenS; i++)
        {
            hash[(s[i] - 'a') % 60]++;
        }
        for (int i = 0; i < lenS; i++)
        {
            if (hash[(t[i] - 'a') % 60] > 0)
            {
                isAnagram = true;
                hash[(t[i] - 'a') % 60]--;
            }
            else
            {
                return false;
            }
        }
    }

    return isAnagram;
}

int main()
{

    string s = "a";
    string t = "nagaram";

    if (anagram(s, t))
    {
        cout << " anagram()";
    }

    return 0;
}

//.................................

class Solution
{
public:
    bool isAnagram(std::string s, std::string t)
    {
        if (s.size() != t.size())
            return false; // If lengths are different, not an anagram

        unordered_map<char, int> count;

        // Count the frequency of characters in s and decrement for t
        for (int i = 0; i < s.size(); i++)
        {
            count[s[i]]++;
            count[t[i]]--;

            // Remove character if count becomes zero
            if (count[s[i]] == 0)
                count.erase(s[i]);
            if (count[t[i]] == 0)
                count.erase(t[i]);
        }

        return count.empty(); // If the map is empty, it's an anagram
    }
};
