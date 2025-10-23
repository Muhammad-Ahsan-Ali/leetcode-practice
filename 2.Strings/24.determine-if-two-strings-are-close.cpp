class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        if (word1.length() != word2.length())
            return false;

        vector<int> freq1(27, 0);
        vector<int> freq2(27, 0);
        unordered_map<int, int> mp;

        for (auto c : word1)
            freq1[c - 'a']++;

        for (auto c : word2)
            freq2[c - 'a']++;

        for (int i = 0; i < 27; i++)
        {
            if (freq1[i] && !freq2[i] || !freq1[i] && freq2[i])
                return false;
        }

        for (auto freq : freq1)
            if (freq)
                mp[freq]++;

        for (auto freq : freq2)
            if (freq && mp.find(freq) != mp.end())
            {
                mp[freq]--;
                if (mp[freq] == 0)
                    mp.erase(freq);
            }
            else if (freq)
                return false;

        return (mp.size() == 0);
    }
};

// optmized

class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        if (word1.size() != word2.size())
            return false;

        vector<int> freq1(26, 0), freq2(26, 0);
        for (char c : word1)
            freq1[c - 'a']++;
        for (char c : word2) 
            freq2[c - 'a']++;

        // Both must have the same unique characters
        for (int i = 0; i < 26; i++)
        {
            if ((freq1[i] == 0) != (freq2[i] == 0))
                return false;
        }

        // Compare frequency multisets
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());
        return freq1 == freq2;
    }
};
