class Solution
{
public:
    // Helper function to compute the maximum path sum
    int maxPathSumHelper(TreeNode *root, int &globalMax)
    {
        if (!root) // Base case: if the node is null, return 0
            return 0;

        // Recursively compute the maximum sum of the left and right subtrees
        // If a subtree contributes a negative sum, we ignore it by taking max(0, subtree_sum)
        int leftWeight = max(0, maxPathSumHelper(root->left, globalMax));
        int rightWeight = max(0, maxPathSumHelper(root->right, globalMax));

        // Compute the sum of the path passing through the current node
        int currentPathSum = leftWeight + root->val + rightWeight;

        // Update the global maximum path sum if this path is greater
        globalMax = max(globalMax, currentPathSum);

        // Return the maximum path sum including the current node and one of its subtrees
        return root->val + max(leftWeight, rightWeight);
    }

    // Function to find the maximum path sum in the binary tree
    int maxPathSum(TreeNode *root)
    {
        int globalMax = INT_MIN;           // Initialize global max to the smallest possible integer
        maxPathSumHelper(root, globalMax); // Start recursion to find max path sum
        return globalMax;                  // Return the maximum path sum found
    }
};
