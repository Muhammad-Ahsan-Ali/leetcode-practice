class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int l = 0;
        int r = 0;
        vector<int> hash(26, 0);
        int maxLen = 0;
        int maxFreq = 0;
        int len = s.length();

        while (r < len)
        {
            hash[s[r] - 'A']++;
            maxFreq = max(maxFreq, hash[s[r] - 'A']);

            while ((r - l + 1) - maxFreq > k)
            {
                hash[s[l] - 'A']--;
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};