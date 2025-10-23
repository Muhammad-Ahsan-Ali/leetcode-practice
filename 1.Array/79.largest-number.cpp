class Solution
{

    struct comp
    {
        bool operator()(int &a, int &b) const
        {
            string as = to_string(a);
            string bs = to_string(b);

            return as + bs > bs + as;
        }
    };

public:
    string largestNumber(vector<int> &nums)
    {

        bool check0 = 1;
        for (auto num : nums)
            if (num != 0)
                check0 = 0;

        if (check0)
            return "0";

        sort(nums.begin(), nums.end(), comp());

        string ans;

        for (auto num : nums)
            ans += to_string(num);
        return ans;
    }
};

// optimization

class Solution
{

    struct comp
    {
        bool operator()(string &a, string &b) const
        {
            return a + b > b + a;
        }
    };

public:
    string largestNumber(vector<int> &nums)
    {

        vector<string> strs;

        bool check0 = 1;
        for (auto num : nums)
        {
            if (num != 0)
                check0 = 0;
            strs.push_back(to_string(num));
        }

        if (check0)
            return "0";

        sort(strs.begin(), strs.end(), comp());

        string ans;

        for (auto &s : strs)
            ans += s;
        return ans;
    }
};