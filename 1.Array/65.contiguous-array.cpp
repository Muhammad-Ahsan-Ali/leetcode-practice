class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> preSumMap;

        int maxLen = 0;
        int sum = 0;

        for (int i = 0; i < n; i++)
        {

            if (nums[i])
                sum++;
            else
                sum--;
            if (sum == 0)
                maxLen = max(maxLen, i + 1);

            if (preSumMap.find(sum) != preSumMap.end())
            {
                int len = i - preSumMap[sum];
                maxLen = max(maxLen, len);
            }
            if (preSumMap.find(sum) == preSumMap.end())
                preSumMap[sum] = i;
        }
        return maxLen;
    }
};