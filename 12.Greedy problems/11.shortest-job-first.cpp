class Solution
{
public:
    long long solve(vector<int> &bt)
    {
        int totalWeightTime = 0;
        int startTime = 0;
        int n = bt.size();

        sort(bt.begin(), bt.end());

        for (int i = 0; i < n; i++)
        {
            totalWeightTime += startTime;
            startTime += bt[i];
        }

        return totalWeightTime / n;
    }
};