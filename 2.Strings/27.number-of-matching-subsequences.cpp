
// o(n*m)

class Solution
{

private:
public:
    int numMatchingSubseq(string s, vector<string> &words)
    {
        int cnt = 0;
        unordered_map<char, vector<int>> mp;

        for (int i = 0; i < s.length(); i++)
            mp[s[i]].push_back(i);

        function<bool(string &)> isSubsequence = [&](string &word) -> bool
        {
            int idx = 0;
            for (auto c : word)
            {
                auto &arr = mp[c];
                auto it = lower_bound(arr.begin(), arr.end(), idx);
                if (it == arr.end())
                    return false;
                idx = *it + 1;
            }

            return true;
        };

        for (auto word : words)
            if (isSubsequence(word))
                cnt++;

        return cnt;
    }
};

// o(n+m)
class Solution
{
public:
    int numMatchingSubseq(string s, vector<string> &words)
    {

        vector<vector<pair<int, int>>> bucket(26);

        for (int i = 0; i < words.size(); i++)
            bucket[words[i][0] - 'a'].push_back({i, 0});

        int cnt = 0;
        for (auto c : s)
        {
            auto cur = move(bucket[c - 'a']);
            bucket[c - 'a'].clear();

            for (auto [wordIdx, charPos] : cur)
            {
                charPos++;
                if (charPos == words[wordIdx].size())
                    cnt++;
                else
                {
                    char nextChar = words[wordIdx][charPos];
                    bucket[nextChar - 'a'].push_back({wordIdx, charPos});
                }
            }
        }
        return cnt;
    }
};