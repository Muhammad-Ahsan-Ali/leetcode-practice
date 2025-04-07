class Solution
{
private:
    void helper(vector<string> &output, string temp, int n, int starts, int close)
    {
        if (close == n)
            output.push_back(temp);

        if (starts < n)
            helper(output, temp + '(', n, starts + 1, close);

        if (starts > close && close < n)
            helper(output, temp + ')', n, starts, close + 1);
    }

public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> output;
        string temp;
        helper(output, temp, n, 0, 0);
        return output;
    }
};