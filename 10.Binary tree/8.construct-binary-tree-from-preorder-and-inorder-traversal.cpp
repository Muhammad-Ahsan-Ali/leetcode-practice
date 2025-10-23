
class Solution
{
public:
    // Function to build a binary tree from preorder and inorder traversal
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        // Map to store the index of each node value in the inorder array
        map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
            // Store value and its index
        }

        // Call the recursive function to construct the tree
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
    }

    // Recursive function to build the tree
    TreeNode *buildTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inoStart, int inoEnd, map<int, int> &mp)
    {
        // Base case: If the starting index is greater than the ending index, return null
        if (preStart > preEnd || inoStart > inoEnd)
            return nullptr;

        // Create the root node using the first element of preorder traversal
        TreeNode *root = new TreeNode();
        root->val = preorder[preStart]; // Root node is always the first element in preorder

        // Find the index of the root in the inorder array
        int indRoot = mp[preorder[preStart]];

        // Calculate the number of elements in the left subtree
        int numsLeft = indRoot - inoStart;

        // Recursively construct the left subtree
        root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inoStart, indRoot - 1, mp);

        // Recursively construct the right subtree
        root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, indRoot + 1, inoEnd, mp);

        // Return the constructed root node
        return root;
    }
};
