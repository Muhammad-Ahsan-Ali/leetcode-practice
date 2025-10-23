class Solution
{
public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {

        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; i++)
            for (int j = 1; j < m; j++)
                matrix[i][j] += matrix[i][j - 1];

        int cnt = 0;
        for (int left = 0; left < m; left++)
            for (int right = left; right < m; right++)
            {
                int curSum = 0;
                unordered_map<int, int> freq;
                freq[0] = 1;

                for (int r = 0; r < n; r++)
                {
                    curSum += matrix[r][right] - (left > 0 ? matrix[r][left - 1] : 0);
                    int rem = curSum - target; // not needed sum occured before
                    if (freq.count(rem))
                        cnt += freq[rem];
                    freq[curSum]++;
                }
            }
        return cnt;
    }
};