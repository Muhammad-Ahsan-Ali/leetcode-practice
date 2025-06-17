class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
    {
        int n = firstList.size();
        int m = secondList.size();

        int i = 0;
        int j = 0;
        vector<vector<int>> output;

        while (i < n && j < m)
        {
            int strt1 = firstList[i][0];
            int strt2 = secondList[j][0];
            int end1 = firstList[i][1];
            int end2 = secondList[j][1];
            int strt = max(strt1, strt2);
            int end = min(end1, end2);

            if (strt <= end)
                output.push_back({strt, end});

            if (end1 < end2)
                i++;
            else
                j++;
        }

        return output;
    }
};