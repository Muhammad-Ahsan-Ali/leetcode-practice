class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        int cnt = 0;
        unordered_map<int, int> preSumMap;
        int sum = 0;

        preSumMap[0] = 1;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            int rem = sum - k;
            if (preSumMap.find(rem) != preSumMap.end())
            {
                cnt += preSumMap[rem];
            }
            preSumMap[sum]++;
        }
        return cnt;
    }
};
