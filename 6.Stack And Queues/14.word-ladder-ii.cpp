class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string> &wordList)
    {

        string beginWord = beginWord;
        set<string> st(wordList.begin(), wordList.end());
        if (st.find(endWord) == st.end())
            return {};
        queue<vector<string>> q;
        q.push({{beginWord}});
        vector<vector<string>> res;
        vector<string> lvlTrvrsd;
        lvlTrvrsd.push_back(beginWord);
        int lvl = 0;

        while (!q.empty())
        {
            vector<string> vec = q.front();
            string curWord = vec.back();
            q.pop();

            if (vec.size() > lvl)
            {
                lvl++;
                for (auto it : lvlTrvrsd)
                    st.erase(it);
                lvlTrvrsd.clear();
            }

            if (curWord == endWord)
            {
                if (!res.empty() && res[0].size() < vec.size())
                    return res;
                res.push_back(vec);
            }

            for (int i = 0; i < curWord.length(); i++)
            {
                string temp = curWord;
                for (char c = 'a'; c <= 'z'; c++)
                {
                    temp[i] = c;
                    if (st.find(temp) != st.end())
                    {
                        vec.push_back(tem);
                        q.push(vec);
                        lvlTrvrsd.push_back(temp);
                        vec.pop_back();
                    }
                }
            }
        }

        return res;
    }
};

// Optimized
class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {

        set<string> s(wordList.begin(), wordList.end());
        s.erase(beginWord);
        if (s.find(endWord) == s.end())
            return {};

        queue<pair<string, int>> q;
        unordered_map<string, int> mp;
        vector<vector<string>> res;
        mp[beginWord] = 1;
        q.push({beginWord, 1});

        while (!q.empty())
        {
            string curWord = q.front().first;
            int curStp = q.front().second;
            q.pop();

            if (curWord == endWord)
                break;

            for (int i = 0; i < curWord.length(); i++)
            {
                string temp = curWord;
                for (char c = 'a'; c <= 'z'; c++)
                {
                    temp[i] = c;
                    if (s.find(temp) != s.end())
                    {
                        q.push({temp, curStp + 1});
                        mp[temp] = curStp + 1;
                        s.erase(temp);
                    }
                }
            }
        }

        auto dfs = [&](auto &&dfs, string curWrd, vector<string> seq) -> void
        {
            if (curWrd == beginWord)
            {
                reverse(seq.begin(), seq.end());
                res.push_back(seq);
                reverse(seq.begin(), seq.end());
                return;
            }

            int stp = mp[curWrd];

            for (int i = 0; i < curWrd.length(); i++)
            {
                string temp = curWrd;
                for (char c = 'a'; c <= 'z'; c++)
                {
                    temp[i] = c;
                    if (mp.find(temp) != mp.end() && stp == mp[temp] + 1)
                    {
                        seq.push_back(temp);
                        dfs(dfs, temp, seq);
                        seq.pop_back();
                    }
                }
            }
        };

        dfs(dfs, endWord, {endWord});

        return res;
    }
};