class Solution
{

public:
    int maxScoreWords(vector<string> &words, vector<char> &letters,
                      vector<int> &score)
    {
        int maxScore = 0;
        int n = words.size();
        unordered_map<char, int> mp;

        for (auto &c : letters)
            mp[c]++;

        function<bool(string &)> wordCantBeFormed = [&](string &word)
        {
            unordered_map<char, int> cnt;

            for (auto c : word)
                cnt[c]++;
            for (auto it : cnt)
                if (!mp.count(it.first) || mp[it.first] < it.second)
                    return 1;

            return 0;
        };

        function<void(string &)> removeFromMap = [&](string &word)
        {
            for (auto &c : word)
            {
                mp[c]--;
                if (mp[c] == 0)
                    mp.erase(c);
            }
        };

        function<void(string &)> addToMap = [&](string &word)
        {
            for (auto &c : word)
                mp[c]++;
        };

        function<int(string &)> cal = [&](string &word)
        {
            int tscore = 0;
            for (auto &c : word)
                tscore += score[c - 'a'];
            return tscore;
        };

        function<void(int, int)> backTrack = [&](int pos, int curScore)
        {
            if (pos == n)
            {
                maxScore = max(maxScore, curScore);
                return;
            }

            for (int i = pos; i < n; i++)
            {
                if (wordCantBeFormed(words[i]))
                {
                    backTrack(i + 1, curScore);
                    continue;
                }
                removeFromMap(words[i]);
                int tScore = cal(words[i]) + curScore;
                backTrack(i + 1, tScore);
                addToMap(words[i]);
            }
        };

        backTrack(0, 0);
        return maxScore;
    }
};

// optimization

class Solution
{

public:
    int maxScoreWords(vector<string> &words, vector<char> &letters,
                      vector<int> &score)
    {
        int maxScore = 0;
        int n = words.size();
        vector<int> mp(26, 0);

        for (auto &c : letters)
            mp[c - 'a']++;

        vector<vector<int>> freq(n, vector<int>(26, 0));
        vector<int> wordScore(n, 0);

        for (int i = 0; i < n; i++)
            for (auto &c : words[i])
            {
                freq[i][c - 'a']++;
                wordScore[i] += score[c - 'a'];
            }

        function<bool(int)> wordCantBeFormed = [&](int idx)
        {
            for (int j = 0; j < 26; j++)
                if (freq[idx][j] > mp[j])
                    return 1;
            return 0;
        };

        function<void(int)> removeFromMap = [&](int idx)
        {
            for (int j = 0; j < 26; j++)
                mp[j] -= freq[idx][j];
        };

        function<void(int)> addToMap = [&](int idx)
        {
            for (int j = 0; j < 26; j++)
                mp[j] += freq[idx][j];
        };

        function<int(int)> cal = [&](int idx)
        {
            return wordScore[idx];
        };

        function<void(int, int)> backTrack = [&](int pos, int curScore)
        {
            if (pos == n)
            {
                maxScore = max(maxScore, curScore);
                return;
            }
            backTrack(pos + 1, curScore);

            if (wordCantBeFormed(pos))
                return;

            removeFromMap(pos);
            int tScore = cal(pos) + curScore;
            backTrack(pos + 1, tScore);
            addToMap(pos);
        };

        backTrack(0, 0);
        return maxScore;
    }
};
