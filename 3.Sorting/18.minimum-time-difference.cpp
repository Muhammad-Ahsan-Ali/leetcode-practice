class Solution
{
public:
    int findMinDifference(vector<string> &timePoints)
    {
        // In-place sort with total minutes as comparison
        sort(timePoints.begin(), timePoints.end(), [&](string &a, string &b)
             {
            int minA = stoi(a.substr(0, 2)) * 60 + stoi(a.substr(3, 2));
            int minB = stoi(b.substr(0, 2)) * 60 + stoi(b.substr(3, 2));
            return minA < minB; });

        int n = timePoints.size();
        int mini = INT_MAX;

        // Compare adjacent times
        for (int i = 1; i < n; i++)
        {
            int t1 = stoi(timePoints[i - 1].substr(0, 2)) * 60 + stoi(timePoints[i - 1].substr(3, 2));
            int t2 = stoi(timePoints[i].substr(0, 2)) * 60 + stoi(timePoints[i].substr(3, 2));
            mini = min(mini, t2 - t1);
        }

        // Compare last and first (circular wrap)
        int first = stoi(timePoints[0].substr(0, 2)) * 60 + stoi(timePoints[0].substr(3, 2));
        int last = stoi(timePoints[n - 1].substr(0, 2)) * 60 + stoi(timePoints[n - 1].substr(3, 2));
        mini = min(mini, (1440 - last + first));

        return mini;
    }
};
