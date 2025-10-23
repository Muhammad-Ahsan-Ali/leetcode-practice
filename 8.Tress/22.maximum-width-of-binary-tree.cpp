
class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;

        unsigned long long maxWidth = 0;
        queue<pair<TreeNode *, unsigned long long>> q;
        q.push({root, 1});

        while (!q.empty())
        {
            int sz = q.size();
            unsigned long long first = q.front().second;
            unsigned long long last = q.back().second;
            maxWidth = max(maxWidth, last - first + 1);

            for (int i = 0; i < sz; i++)
            {
                auto [node, idx] = q.front();
                q.pop();
                unsigned long long norm = idx - first;
                if (node->left)
                    q.push({node->left, norm * 2 + 1});
                if (node->right)
                    q.push({node->right, norm * 2 + 2});
            }
        }

        return static_cast<int>(maxWidth);
    }
};
