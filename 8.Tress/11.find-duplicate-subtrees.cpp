
class Solution
{
private:
    string serialize(TreeNode *root)
    {
        if (!root)
            return "null";

        string result;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            if (node)
            {
                result += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
            else
            {
                result += "null,";
            }
        }

        result.pop_back();
        return result;
    }

public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        unordered_map<string, int> hash;
        vector<TreeNode *> ans;

        auto dfs = [&](auto &dfs, TreeNode *curRoot) -> void
        {
            if (!curRoot)
                return;
            string temp = serialize(curRoot);
            hash[temp]++;
            if (hash[temp] == 2)
                ans.push_back(curRoot);
            dfs(dfs, curRoot->left);
            dfs(dfs, curRoot->right);
        };
        dfs(dfs, root);
        return ans;
    }
};

// optmized

class Solution
{
public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        unordered_map<string, int> hash;
        vector<TreeNode *> ans;

        auto dfs = [&](auto &dfs, TreeNode *curRoot) -> string
        {
            if (!curRoot)
                return "#";
            string left = dfs(dfs, curRoot->left);
            string right = dfs(dfs, curRoot->right);
            string temp = to_string(curRoot->val) + "," + left + "," + right;
            if (++hash[temp] == 2)
                ans.push_back(curRoot);
            return temp;
        };
        dfs(dfs, root);
        return ans;
    }
};