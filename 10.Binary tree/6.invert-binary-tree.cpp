class Solution
{
public:
    void mirroNodes(TreeNode *root)
    {

        if (root == nullptr)
            return;

        TreeNode *leftBranch = root->left;
        root->left = root->right;
        root->right = leftBranch;

        mirroNodes(root->left);
        mirroNodes(root->right);
    }

    TreeNode *invertTree(TreeNode *root)
    {
        mirroNodes(root);

        return root;
    }
};
