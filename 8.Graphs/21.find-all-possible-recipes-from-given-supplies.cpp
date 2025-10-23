class Solution
{
public:
    vector<string> findAllRecipes(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies)
    {

        unordered_map<string, vector<string>> adj;
        unordered_map<string, int> indeg;
        unordered_set<string> st(recipes.begin(), recipes.end());

        int n = recipes.size();
        for (int i = 0; i < n; i++)
            for (auto &ingredient : ingredients[i])
            {
                adj[ingredient].push_back(recipes[i]);
                indeg[recipes[i]]++;
            }

        queue<string> q;

        for (auto &supply : supplies)
            q.push(supply);

        vector<string> ans;

        while (!q.empty())
        {
            string curSupply = q.front();
            q.pop();

            if (st.contains(curSupply))
                ans.push_back(curSupply);

            for (auto &recipe : adj[curSupply])
            {
                indeg[recipe]--;
                if (indeg[recipe] == 0)
                    q.push(recipe);
            }
        }

        return ans;
    }
};