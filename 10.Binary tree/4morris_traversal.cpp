void preOrder(TreeNode *root)
{
    while (root) // Continue while the current node is not null
    {
        // If there is no left subtree, print the current node and move to the right
        if (root->left == nullptr)
        {
            cout << root->val;  // Print current node (preorder step)
            root = root->right; // Move to the right subtree
        }
        else
        {
            // Find the rightmost node in the left subtree (predecessor)
            TreeNode *cur = root->left;
            while (cur->right && cur->right != root)
            {
                cur = cur->right; // Move to the rightmost node
            }

            // If the right pointer of the predecessor is null, establish a temporary link
            if (cur->right == nullptr)
            {
                cur->right = root; // Create a temporary link back to the root
                cout << root->val; // Print the current node (preorder step)
                root = root->left; // Move to the left subtree
            }
            else
            {
                // If the link already exists, remove it and move to the right subtree
                cur->right = nullptr; // Restore the tree by removing the link
                root = root->right;   // Move to the right subtree
            }
        }
    }
}

// inorder
void inOrder(TreeNode *root)
{
    while (root) // Continue while the current node is not null
    {
        if (root->left == nullptr) // If there is no left subtree, print and move right
        {
            cout << root->val << " "; // Print current node (inorder step)
            root = root->right;       // Move to the right subtree
        }
        else
        {
            // Find the rightmost node (predecessor) in the left subtree
            TreeNode *cur = root->left;
            while (cur->right && cur->right != root)
            {
                cur = cur->right; // Move to the rightmost node
            }

            if (cur->right == nullptr) // If the predecessor has no link, establish a temporary link
            {
                cur->right = root; // Create a thread (temporary link)
                root = root->left; // Move to the left subtree
            }
            else
            {
                // If the link already exists, remove it and process the current node
                cur->right = nullptr;     // Restore the tree
                cout << root->val << " "; // Print current node (inorder step)
                root = root->right;       // Move to the right subtree
            }
        }
    }
}
