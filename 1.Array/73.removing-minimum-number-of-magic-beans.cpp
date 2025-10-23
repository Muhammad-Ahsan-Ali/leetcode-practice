class Solution
{
public:
    long long minimumRemoval(vector<int> &beans)
    {
        long long ans = LLONG_MAX;

        sort(beans.begin(), beans.end());
        long long sum = accumulate(beans.begin(), beans.end(), 0LL);

        int n = beans.size();
        for (int i = 0; i < n; i++)
        {
            long long beans_left = (n - i) * 1LL * beans[i];
            ans = min(ans, sum - beans_left);
        }
        return ans;
    }
};