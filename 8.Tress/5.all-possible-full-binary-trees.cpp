/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution
{
private:
    unordered_map<int, vector<TreeNode *>> mp;

public:
    vector<TreeNode *> allPossibleFBT(int n)
    {
        if (n % 2 == 0)
            return {};

        if (n == 1)
        {
            TreeNode *node = new TreeNode(0);
            return {node};
        }

        if (mp.find(n) != mp.end())
            return mp[n];

        vector<TreeNode *> res;

        for (int i = 1; i < n; i += 2)
        {
            vector<TreeNode *> leftPos = allPossibleFBT(i);
            vector<TreeNode *> rightPos = allPossibleFBT(n - i - 1);

            for (auto &&l : leftPos)
            {
                for (auto &&r : rightPos)
                {
                    TreeNode *root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }

        return mp[n] = res;
        ;
    }
};