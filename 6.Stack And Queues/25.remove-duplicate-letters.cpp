class Solution
{
public:
    string removeDuplicateLetters(string s)
    {

        unordered_map<char, int> mp;
        for (auto c : s)
            mp[c]++;

        unordered_set<char> visitied;

        string ans = "";

        stack<char> st;

        for (auto c : s)
        {
            while (!st.empty() && st.top() > c && mp[st.top()] > 0 &&
                   !visitied.count(c))
            {
                char ch = st.top();
                visitied.erase(ch);
                st.pop();
            }

            if (!visitied.count(c))
            {
                visitied.insert(c);
                st.push(c);
            }
            mp[c]--;
        }

        while (!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};

// bit optimized
class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        // Count remaining frequencies
        unordered_map<char, int> mp;
        for (char c : s)
            mp[c]++;

        unordered_set<char> visited;
        string ans;

        for (char c : s)
        {
            mp[c]--;

            if (visited.count(c))   
                continue;

            while (!ans.empty() && ans.back() > c && mp[ans.back()] > 0)
            {
                visited.erase(ans.back());`
                ans.pop_back();
            }

            ans.push_back(c);
            visited.insert(c);
        }

        return ans;
    }
};
