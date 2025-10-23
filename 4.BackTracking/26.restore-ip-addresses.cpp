class Solution
{
private:
    vector<string> ans;

public:
    vector<string> restoreIpAddresses(string s)
    {
        int n = s.length();

        function<void(int, int, string)> util = [&](int idx, int cnt, string temp)
        {
            if (cnt == 4 && idx == n)
            {
                ans.push_back(temp);
                return;
            }
            if (cnt == 4 || idx == n)
                return;

            for (int len = 1; len <= 3 && idx + len <= n; len++)
            {
                string part = s.substr(idx, len);

                // Skip leading zeros unless single "0"
                if (part.size() > 1 && part[0] == '0')
                    continue;

                // Convert to number and check range
                int val = stoi(part);
                if (val > 255)
                    continue;

                // Add dot only if not the first segment
                string next = (cnt == 0) ? part : temp + "." + part;

                util(idx + len, cnt + 1, next);
            }
        };

        util(0, 0, "");
        return ans;
    }
};
