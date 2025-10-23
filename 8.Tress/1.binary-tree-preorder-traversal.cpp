
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        auto pTr = [&](auto &&pTr, TreeNode *nod) -> void
        {
            if (!nod)
                return;
            ans.push_back(nod->val);
            pTr(pTr, nod->left);
            pTr(pTr, nod->right);
        };
        pTr(pTr, root);
        return ans;
    }
};

//
class Solution
{
public:
    vector<int>
    preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;

        stack<TreeNode *> st;
        st.push(root);

        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();
            ans.push_back(node->val);

            // Push right child first so that left child is processed first
            if (node->right)
                st.push(node->right);
            if (node->left)
                st.push(node->left);
        }

        return ans;
    }
};
