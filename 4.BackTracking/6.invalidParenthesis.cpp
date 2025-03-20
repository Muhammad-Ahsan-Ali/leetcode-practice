#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValidExpression(string s)
{
    int track = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            track++;
        }
        if (s[i] == ')')
        {
            track--;
        }
        if (track < 0)
        {
            return false;
        }
    }

    if (track == 0)
    {
        return true;
    }
    return false;
}

int invalidBrackets(string s)
{
    int count = 0;
    int track = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            track++;
        }
        if (s[i] == ')')
        {
            track--;
        }
        if (track < 0)
        {
            track++;
            count++;
        }
    }
    count += track;
    return count;
}

bool isValid(string temp, string s)
{

    if (isValidExpression(temp) && (temp.length() == s.length() - invalidBrackets(s)))
    {
        return true;
    }

    return false;
}

void sol(int index, vector<string> &output, string temp, string s)
{
    if (index >= s.length())
    {
        if (isValid(temp, s))
        {
            output.push_back(temp);
        }
        return;
    }
    temp.push_back(s[index]);
    sol(index + 1, output, temp, s);
    temp.pop_back();
    sol(index + 1, output, temp, s);
}

vector<string> removeInvalidParentheses(string s)
{
    vector<string> output;
    string temp;
    sol(0, output, temp, s);
    return output;
}

int main()
{

    string s = "()())()";
    removeInvalidParentheses(s);

    return 0;
}