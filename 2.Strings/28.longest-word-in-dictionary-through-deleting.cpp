class Solution
{
public:
    string findLongestWord(string s, vector<string> &dictionary)
    {
        unordered_map<char, vector<pair<int, int>>> mp;

        for (int i = 0; i < dictionary.size(); i++)
            mp[dictionary[i][0]].push_back({i, 0});

        string ans;

        for (auto c : s)
        {
            auto cur = std::move(mp[c]);
            mp.erase(c);

            for (auto [wordIdx, charPos] : cur)
            {
                charPos++;
                string word = dictionary[wordIdx];
                if (charPos == word.length())
                {
                    if (ans.length() == 0 || ans.length() < word.length() || (ans.length() == word.length() && word < ans))
                        ans = word;
                }
                else
                    mp[dictionary[wordIdx][charPos]].push_back(
                        {wordIdx, charPos});
            }
        }
        return ans;
    }
};