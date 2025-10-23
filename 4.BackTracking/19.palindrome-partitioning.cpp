
class Solution
{
private:
    bool isPalindrome(string &s, int index, int i)
    {

        while (index < i)
        {
            if (s[index++] != s[i--])
            {
                return false;
            }
        }

        return true;
    }

    void util(int index, vector<vector<string>> &ans, vector<string> temp,
              string &s)
    {

        if (index >= s.length())
        {
            ans.push_back(temp);
            return;
        }

        for (int i = index; i < s.length(); i++)
        {
            if (isPalindrome(s, index, i))
            {
                temp.push_back(s.substr(index, i - index + 1));
                util(i + 1, ans, temp, s);
                temp.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s)
    {

        vector<vector<string>> ans;

        vector<string> temp;

        util(0, ans, temp, s);

        return ans;
    }
};