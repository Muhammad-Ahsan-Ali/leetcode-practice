class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> st;
        TreeNode *current = root;

        while (current || !st.empty())
        {
            // Go as left as possible
            while (current)
            {
                st.push(current);
                current = current->left;
            }

            // Process the node
            current = st.top();
            st.pop();
            ans.push_back(current->val);

            // Go to the right subtree
            current = current->right;
        }

        return ans;
    }
};
