
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals,
                               vector<int> &newInterval)
    {
        int n = intervals.size();
        vector<vector<int>> output;
        if (n == 0)
        {
            return {newInterval};
        }
        int i = 0;

        while (i < n && intervals[i][1] < newInterval[0])
        {
            output.push_back(intervals[i]);
            i++;
        }

        while (i < n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        output.push_back(newInterval);
        while (i < n)
        {
            output.push_back(intervals[i]);
            i++;
        }
        return output;
    }
};