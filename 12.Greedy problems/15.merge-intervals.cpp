class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {

        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> output;

        for (int i = 0; i < n; i++)
        {
            if (output.empty() || output.back()[1] < intervals[i][0])
            {
                output.push_back(intervals[i]);
            }
            else
            {
                output.back()[1] = max(output.back()[1], intervals[i][1]);
            }
        }
        return output;
    }
};