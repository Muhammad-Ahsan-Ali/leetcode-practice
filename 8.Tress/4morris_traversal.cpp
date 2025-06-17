void preOrder(TreeNode *root)
{
    TreeNode *cur=root;
    while (cur)
    {

        if (cur->left == nullptr)
        {
            cout << cur->val;
            cur = cur->right;
        }
        else
        {
            TreeNode *prdCsr = cur->left;
            while (prdCsr->right && prdCsr->right != cur)
            {
                prdCsr = prdCsr->right;
            }

            if (prdCsr->right == nullptr)
            {
                prdCsr->right = cur;
                cout << cur->data;
                cur = cur->left;
            }
            else
            {
                prdCsr->right = nullptr;
                cur = cur->right;
            }
        }
    }
}
