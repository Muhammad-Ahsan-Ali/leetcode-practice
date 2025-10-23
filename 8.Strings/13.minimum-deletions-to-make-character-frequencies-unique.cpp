class Solution
{
public:
    int minDeletions(string s)
    {
        vector<int> freq(26, 0);

        for (auto &c : s)
            freq[c - 'a']++;

        sort(freq.begin(), freq.end(), greater<int>());

        int del = 0;
        for (int i = 1; i < 26; i++)
        {
            if (freq[i] >= freq[i - 1])
            {
                int allowedFreq = max(0, freq[i - 1] - 1);
                del += freq[i] - allowedFreq;
                freq[i] = allowedFreq;
            }
        }
        return del;
    }
};