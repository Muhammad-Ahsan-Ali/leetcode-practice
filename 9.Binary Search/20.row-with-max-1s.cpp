class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> &arr)
    {
        int n = arr.size();
        int m = arr[0].size();

        int ind = -1;
        int maxCnt = 0;

        for (int i = 0; i < n; i++)
        {
            int cnt = m - (lower_bound(arr[i].begin(), arr[i].end(), 1) - arr[i].begin());
            if (cnt > maxCnt)
            {
                maxCnt = cnt;
                ind = i;
            }
        }
        return ind;
    }
};