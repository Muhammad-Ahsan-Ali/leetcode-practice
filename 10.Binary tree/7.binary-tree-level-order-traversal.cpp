class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> output;
        if (root == nullptr)
            return output;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {

            int levelSize = q.size();
            vector<int> temp;

            for (int i = 0; i < levelSize; ++i)
            {
                TreeNode *cur = q.front();
                q.pop();

                temp.push_back(cur->val);

                if (cur->left != nullptr)
                    q.push(cur->left);

                if (cur->right != nullptr)
                    q.push(cur->right);
            }

            output.push_back(temp);
        }

        return output;
    }
};
