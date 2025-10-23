class Solution
{
public:
    string convert(string s, int numRows)
    {

        if (numRows == 1)
            return s;

        vector<string> rows(min((int)s.length(), numRows));

        bool goingDown = 0;
        int i = 0;
        for (auto c : s)
        {
            rows[i] += c;
            if (i == 0 || i == rows.size() - 1)
                goingDown = !goingDown;
            i += goingDown ? 1 : -1;
        }

        string ans;
        ans.reserve(s.size());
        for (string str : rows)
            ans += str;

        return ans;
    }
};