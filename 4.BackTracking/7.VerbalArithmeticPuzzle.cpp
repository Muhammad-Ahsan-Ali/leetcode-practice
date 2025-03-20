#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int mapDecoder(string s, map<char, int> alphabetsMp)
{
    string temp = "";

    for (int i = 0; i < s.length(); i++)
    {
        temp += to_string(alphabetsMp[s[i]]);
    }
    return stoi(temp);
}

bool sol(int index, string alphabets, map<int, int> digitsMp, map<char, int> alphabetsMp, string s1, string s2, string s3)
{
    if (index >= alphabets.length())
    {
        int num1 = mapDecoder(s1, alphabetsMp);
        int num2 = mapDecoder(s2, alphabetsMp);
        int num3 = mapDecoder(s3, alphabetsMp);

        if (to_string(num1).length() != s1.length() ||
            to_string(num2).length() != s2.length() ||
            to_string(num3).length() != s3.length())
        {
            return false;
        }

        if (num1 + num2 == num3)
        {
            return true;
        }

        return false;
    }

    for (int i = 0; i < 10; i++)
    {
        if (digitsMp[i] == -1)
        {
            alphabetsMp[alphabets[index]] = i;
            digitsMp[i] = 1;
            bool output = sol(index + 1, alphabets, digitsMp, alphabetsMp, s1, s2, s3);

            if (output)
            {
                return true;
            }

            digitsMp[i] = -1;
        }
    }
    return false;
}

bool isSolvable(vector<string> &words, string result)
{

    string s1 = words[0];
    string s2 = words[1];
    string s3 = result;

    set<char> uniqueAlphabetsSet;

    for (const auto &word : words)
    {
        for (char ch : word)
        {
            uniqueAlphabetsSet.insert(ch);
        }
    }

    for (char ch : result)
    {
        uniqueAlphabetsSet.insert(ch);
    }

    string alphabets(uniqueAlphabetsSet.begin(), uniqueAlphabetsSet.end());

    map<int, int> digitsMp;
    map<char, int> alphabetsMp;

    // Assume you want to map digits (0-9) initially to -1

    for (int i = 0; i < 10; ++i)
    {
        digitsMp[i] = -1;
    }

    return sol(0, alphabets, digitsMp, alphabetsMp, s1, s2, s3);
}

int main()
{

    vector<string> words = {"SEND", "MORE"};
    string result = "MONEY";

    cout << isSolvable(words, result);

    return 0;
}