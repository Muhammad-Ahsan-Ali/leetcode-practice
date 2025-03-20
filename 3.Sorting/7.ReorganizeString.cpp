#include <iostream>
#include <vector>
using namespace std;
bool isUnique(string s)
{
    for (int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            return false;
        }
    }
    return true;
}

string permuteHelper(string &s, int index)
{
    int len = len;

    if (index >= len)
    {
        if (isUnique(s))
        {
            return s;
        }

        return "";
    }

    for (int i = index; i < len; i++)
    {
        swap(s[i], s[index]);

        string result = permuteHelper(s, index + 1);

        if (result != "")
        {
            return result;
        }

        swap(s[i], s[index]);
    }

    return "";
}

string reorganizeString(string s)
{
    int hash[256] = {0};
    int maxFreq = 0;
    char letter = s[0];
    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i] - 'A']++;
        if (hash[s[i] - 'A'] > (s.size() + 1 / 2))
        {
            return "";
        }
        if (hash[s[i] - 'A'] > maxFreq)
        {
            maxFreq = hash[s[i] - 'A'];
            letter = s[i];
        }
    }

    string result(s.size(), ' ');

    int index = 0;
    while (hash[letter - 'A'] != 0)
    {
        result[index] = letter;
        hash[letter - 'A']--;
        index += 2;
    }

    for (int i = 0; i < 256; i++)
    {
        while (hash[i] != 0)
        {
            if (index >= s.size())
            {
                index = 1;
            }
            result[index] = char(i + 'A');
            index += 2;
            hash[i]--;
        }
    }

    return result;
    // return permuteHelper(s, 0);
}

int main()
{

    string s = "abbabbaaab";
    string s2 = reorganizeString(s);
    int len = s2.size();
    for (int i = 0; i < len; i++)
    {
        cout << s2[i];
    }

    return 0;
}