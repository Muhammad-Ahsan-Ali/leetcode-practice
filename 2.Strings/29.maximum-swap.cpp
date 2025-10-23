class Solution
{
public:
    int maximumSwap(int num)
    {
        string s = to_string(num);
        vector<int> hash(10, -1);

        for (int i = s.length() - 1; i >= 0; i--)
            if (hash[s[i] - '0'] == -1)
                hash[s[i] - '0'] = i;

        bool found = false;
        for (int i = 0; i < s.length() && !found; i++)
            for (int c = '9'; c > s[i]; c--)
                if (hash[c - '0'] != -1 && hash[c - '0'] > i)
                {
                    swap(nums[hash[c - '0']], nums[i]);
                    found = true;
                    break;
                }

        return stoi(s);
    }
};