
class Solution
{
public:
    TreeNode *constructFromPrePost(vector<int> &preorder,
                                   vector<int> &postorder)
    {

        int n = postorder.size();
        map<int, int> mp;

        for (int i = 0; i < n; i++)
            mp[postorder[i]] = i;

        auto buildTree = [&](auto &buildTree, int preStrt, int presEnd,
                             int postStrt) -> TreeNode *
        {
            if (preStrt > presEnd)
                return NULL;
            TreeNode *root = new TreeNode(preorder[preStrt]);
            if (preStrt == presEnd)
                return root;

            int j = mp[preorder[preStrt + 1]];
            int left = j - postStrt + 1;
            root->left =
                buildTree(buildTree, preStrt + 1, preStrt + left, postStrt);
            root->right =
                buildTree(buildTree, preStrt + left + 1, presEnd, j + 1);
            return root;
        };

        return buildTree(buildTree, 0, n - 1, 0);
    }
};