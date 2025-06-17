class Solution
{
public:
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        unordered_set<int> st(to_delete.begin(), to_delete.end());

        vector<TreeNode *> ans;
        queue<TreeNode *> q;

        if (!st.contains(root->val))
            ans.push_back(root);

        auto dfs = [&](auto &&dfs, TreeNode *cur) -> TreeNode *
        {
            if (!cur)
                return NULL;

            cur->left = dfs(dfs, cur->left);
            cur->right = dfs(dfs, cur->right);

            if (st.contains(cur->val))
            {
                if (cur->left)
                    ans.push_back(cur->left);
                if (cur->right)
                    ans.push_back(cur->right);
                return NULL;
            }
            return cur;
        };

        dfs(dfs, root);
        return ans;
    }
};