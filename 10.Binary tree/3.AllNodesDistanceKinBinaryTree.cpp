class Solution
{
public:
    // Helper function to find the target node and store parent pointers
    TreeNode *findTarget(TreeNode *root, TreeNode *target, map<TreeNode *, TreeNode *> &parntMp)
    {
        if (!root) // Base case: if root is null, return nullptr
            return nullptr;

        if (root == target) // If we found the target node, return it
            return root;

        // Store parent pointer of left child
        parntMp[root->left] = root;
        // Recur for left subtree
        TreeNode *leftResult = findTarget(root->left, target, parntMp);

        if (leftResult)
            return leftResult;

        // Store parent pointer of right child
        parntMp[root->right] = root;
        // Recur for right subtree
        return findTarget(root->right, target, parntMp);
    }

    // Helper function to find nodes at distance K
    void distKHelpr(TreeNode *root, int trvrs, int k, vector<int> &arr, map<TreeNode *, TreeNode *> &parntMp, set<TreeNode *> &visited)
    {
        if (!root || visited.find(root) != visited.end()) // Base case: if null or already visited, return
            return;

        visited.insert(root); // Mark node as visited

        if (trvrs == k) // If current distance is k, add node's value to result and return
        {
            arr.push_back(root->val);
            return;
        }

        // Recursive calls to explore all possible directions (parent, left, right)
        if (parntMp[root]) // If parent exists, explore parent
            distKHelpr(parntMp[root], trvrs + 1, k, arr, parntMp, visited);
        distKHelpr(root->left, trvrs + 1, k, arr, parntMp, visited);  // Explore left child
        distKHelpr(root->right, trvrs + 1, k, arr, parntMp, visited); // Explore right child
    }

    // Main function to return all nodes at distance K from the target node
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        map<TreeNode *, TreeNode *> parntMp; // Map to store parent pointers
        parntMp[root] = nullptr;             // Root has no parent

        TreeNode *trgtNode = findTarget(root, target, parntMp); // Find target node and fill parent map

        vector<int> output;      // Stores final result
        set<TreeNode *> visited; // Set to keep track of visited nodes

        distKHelpr(trgtNode, 0, k, output, parntMp, visited); // Start DFS traversal from target node

        return output; // Return the result
    }
};
