
class Solution
{
private:
    unordered_map<pair<int, int>, vector<TreeNode *>> mp;

    vector<TreeNode *> generateTrees(int strt, int end)
    {
        if (strt > end)
            return {nullptr};
        if (mp.contains({start, end}))
            return mp[{start, end}];

        vector<TreeNode *> ans;
        for (int i = strt; i <= end; i++)
        {
            vector<TreeNode *> left = generateTrees(strt, i - 1);
            vector<TreeNode *> right = generateTrees(i + 1, end);

            for (auto l : left)
            {
                for (auto r : right)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return mp[start][end] = ans;
    }

public:
    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
            return {};
        return generateTrees(1, n);
    }
};