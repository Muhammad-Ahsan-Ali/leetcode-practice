class Solution
{
private:
public:
    vector<long long> maximumEvenSplit(long long finalSum)
    {

        long long cur = 2;
        vector<long long> ans;
        if (finalSum % 2)
            return {};
        while (finalSum - cur > cur)
        {

            ans.push_back(cur);
            finalSum -= cur;
            cur += 2;
        }
        ans.push_back(finalSum);

        return ans;
    }
};