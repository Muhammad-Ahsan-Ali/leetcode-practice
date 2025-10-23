/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution
{
    map<pair<TreeNode *, bool>, int> dp;

    int solve(TreeNode *node, bool canTake)
    {

        int res = 0;
        int take = 0;
        int noTake = 0;

        if (dp.contains({node, canTake}))
            return dp[{node, canTake}];
        if (canTake)
        {
            // take
            take += node->val;
            if (node->left)
            {
                take += solve(node->left, false);
            }
            if (node->right)
            {
                take += solve(node->right, false);
            }
        }
        // no take
        if (node->left)
        {
            noTake += solve(node->left, true);
        }
        if (node->right)
        {
            noTake += solve(node->right, true);
        }

        return dp[{node, canTake}] = max(take, noTake);
    }

public:
    int rob(TreeNode *root)
    {
        return solve(root, true);
    }
};

// optmized space

class Solution
{
    // Returns {rob, skip}
    pair<int, int> solve(TreeNode *node)
    {
        if (!node)
            return {0, 0};

        auto left = solve(node->left);
        auto right = solve(node->right);

        // If we rob this node, we cannot rob its children
        int rob = node->val + left.second + right.second;

        // If we skip this node, we can take max of rob/skip from children
        int skip = max(left.first, left.second) + max(right.first, right.second);
 
        return {rob, skip};
    }

public:
    int rob(TreeNode *root)
    {
        auto res = solve(root);
        return max(res.first, res.second);
    }
};
