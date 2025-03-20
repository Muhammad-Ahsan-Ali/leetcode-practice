
void solve(int index, string digits, vector<string> keypad, vector<string> &ans, string temp)
{
    if (index >= digits.length())
    {
        ans.push_back(temp);
        return;
    }

    string value = keypad[digits[index] - '0'];

    for (int i = 0; i < value.length(); i++)
    {
        temp.push_back(value[i]);
        solve(index + 1, digits, keypad, ans, temp);
        temp.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    vector<string> ans;
    if (digits.length() == 0)
    {
        return ans;
    }
    vector<string> keypad = {"", "", "abc", "def", "ghi",
                             "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string temp;
    solve(0, digits, keypad, ans, temp);
    return ans;
}