class Solution
{
public:
    // Helper function to calculate height and update the diameter
    int helper(TreeNode *root, int &diameter)
    {
        if (!root) // Base case: If node is NULL, height is 0
            return 0;

        // Recursively find the height of the left and right subtrees
        int lh = helper(root->left, diameter);
        int rh = helper(root->right, diameter);

        // Update the maximum diameter found so far
        diameter = max(diameter, lh + rh);

        // Return the height of the current subtree (1 + max(left height, right height))
        return 1 + max(lh, rh);
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        int diameter = 0;       // Initialize diameter to 0
        helper(root, diameter); // Call the helper function to compute the diameter
        return diameter;        // Return the final diameter
    }
};
