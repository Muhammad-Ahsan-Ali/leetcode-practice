
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    unordered_map<int, vector<TreeNode *>> mp;

public:
    vector<TreeNode *> allPossibleFBT(int n)
    {
        if (n % 2 == 0)
            return {};

        if (n == 1)
        {
            TreeNode *node = new TreeNode(0);
            return {node};
        }

        if (mp.find(n) != mp.end())
            return mp[n];

        vector<TreeNode *> res;

        for (int i = 1; i < n; i += 2)
        {
            vector<TreeNode *> leftPos = allPossibleFBT(i);
            vector<TreeNode *> rightPos = allPossibleFBT(n - i - 1);

            for (auto &&l : leftPos)
            {
                for (auto &&r : rightPos)
                {
                    TreeNode *root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }

        return mp[n] = res;
    }
};

// DYNAMIC PROGRAMMING
 
class Solution
{
public:
    vector<TreeNode *> allPossibleFBT(int n)
    {
        // Full binary trees must have an odd number of nodes
        if (n % 2 == 0)
            return {};

        // dp[i] will hold all full binary trees with exactly i nodes
        vector<vector<TreeNode *>> dp(n + 1);

        // Base case: one tree of size 1 (just a single node)
        dp[1].push_back(new TreeNode(0));

        // Build up from size = 3,5,7,... up to n
        for (int sz = 3; sz <= n; sz += 2)
        {
            // For each possible split of sz-1 remaining nodes into left/right
            for (int leftCount = 1; leftCount < sz; leftCount += 2)
            {
                int rightCount = sz - 1 - leftCount;
                // Combine every left-tree of size leftCount with every right-tree of size rightCount
                for (TreeNode *L : dp[leftCount])
                {
                    for (TreeNode *R : dp[rightCount])
                    {
                        TreeNode *root = new TreeNode(0);
                        root->left = L;
                        root->right = R;
                        dp[sz].push_back(root);
                    }
                }
            }
        }

        return dp[n];
    }
};
