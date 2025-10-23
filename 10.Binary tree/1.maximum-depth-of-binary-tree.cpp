

class Solution
{

public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int lHeight = (1 + maxDepth(root->left));
        int rHeight = (1 + maxDepth(root->right));

        if (lHeight > rHeight)
        {

            return lHeight;
        }
        else
        {
            return rHeight;
        }
    }
};