class Solution
{
public:
    void flatten(TreeNode *root)
    {
        TreeNode *cur = root; // Pointer to traverse the tree

        while (cur) // Continue while the current node is not null
        {
            if (cur->left) // If there is a left subtree
            {
                TreeNode *temp = cur->right;    // Store the original right subtree
                TreeNode *toPrdcsr = cur->left; // Move to the left subtree

                // Find the rightmost node of the left subtree (predecessor)
                while (toPrdcsr->right)
                {
                    toPrdcsr = toPrdcsr->right;
                }

                // Connect the rightmost node of the left subtree to the stored right subtree
                toPrdcsr->right = temp;

                // Move the left subtree to the right
                cur->right = cur->left;
                cur->left = nullptr; // Set left pointer to null
            }

            // Move to the next right node
            cur = cur->right;
        }
    }
};
