#include <iostream>
#include <algoritm>
using namespace std


class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return nullptr;
        TreeNode* cur = root;
        TreeNode* prev = nullptr;
        while (cur && cur->val != key)
        {
            prev = cur;
              if (cur->val > key) {
                 cur = cur->left;
            } else {
                 cur = cur->right;
            }
        }
        
           if (!cur) return root;
if (!cur->left && !cur->right) {
            if (!prev) {
                 delete cur;
                return nullptr;
            }
            if (prev->left == cur) prev->left = nullptr;
            else prev->right = nullptr;
            delete cur;
        }

            if (!cur->left ) {

                if (!prev) { 
                TreeNode* newRoot = cur->right;
                delete cur;
                return newRoot;
            }

            if (prev->left == cur) prev->left = cur->right;
            else prev->right = cur->right;
delete cur;
            }

            if ( !cur->right) {
                if (!prev) { 
                TreeNode* newRoot = cur->left;
                delete cur;
                return newRoot;
            }
            if (prev->left == cur) prev->left = cur->left;
            else prev->right = cur->left;
delete cur;
            }


            if (cur->left && cur->right) {

                TreeNode* sucPrev = cur;
                TreeNode* suc = cur->right;

                while (suc->left) {
                    sucPrev = suc;
                    suc = suc->left;
                }

                cur->val = suc->val;

                if (sucPrev->left == suc) {
                    sucPrev->left = suc->right;
                } else {
                    sucPrev->right = suc->right;
                }
                delete suc;
            }
        

        return root;
    }
};





class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        // Traverse the tree to find the node
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // Node found
            if (!root->left && !root->right) {
                // Case 1: No children (leaf node)
                delete root;
                return nullptr;
            } else if (!root->left) {
                // Case 2: Only right child
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                // Case 3: Only left child
                TreeNode* temp = root->left;
                delete root;
                return temp;
            } else {
                // Case 4: Two children
                TreeNode* successor = findMin(root->right); // Find successor
                root->val = successor->val;                // Replace value
                root->right = deleteNode(root->right, successor->val); // Delete successor
            }
        }

        return root;
    }

private:
    // Helper function to find the minimum value in a subtree
    TreeNode* findMin(TreeNode* node) {
        while (node->left) {
            node = node->left;
        }
        return node;
    }
};





int main(){

    return 0;
}