
// j - i != nums[j] - nums[i]
// nums[i] - i != nums[j] - j
//
// and
// nC2 =n!/ 2!(n−2)!
//
//        n(𝑛 − 1)(n−2)!
// nC2 = ------------------
//          2!(n−2)!
//
// Simplify :
// 𝑛𝐶2 = 𝑛(𝑛 − 1)/2

class Solution
{
public:
    long long countBadPairs(vector<int> &nums)
    {
        unordered_map<int, long long> freq;
        long long n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int offset = nums[i] - i;
            freq[offset]++;
        }

        long long totalPairs = n * (n - 1) / 2;

        long long goodPairs = 0;
        for (auto &[key, f] : freq)
            if (f > 1)
                goodPairs += f * (f - 1) / 2;

        return totalPairs - goodPairs; // bad pairs
    }
};
