
class Solution {
public:
    void recoverTree(TreeNode* root) {
         TreeNode* first = nullptr;
        TreeNode* mid = nullptr;
        TreeNode* second = nullptr;

        TreeNode* cur = root;
        TreeNode* prev = nullptr;

        while (cur) {

            if (!cur->left) {

                if (prev && prev->val > cur->val) {
                    if (!first) {
                        first = prev;
                        mid = cur;
                    } else {
                        second = cur;
                    }
                }
                prev = cur;
                cur = cur->right;
            }

            else {
                TreeNode* pred = cur->left;

                while (pred->right && pred->right != cur) {
                    pred = pred->right;
                }

                if (!pred->right) {
                    pred->right = cur;
                    cur = cur->left;
                }

                else {
                    
                   if (prev && prev->val > cur->val) {
                        if (!first) {
                            first = prev;
                            mid = cur;
                        } else {
                            second = cur;
                        }
                    }
                    prev = cur;
                    cur = cur->right;
                    pred->right = nullptr;
                }
            }
        }

        if (!second) {
            swap(first, mid);
        } else {
            swap(first, second);
        }
    }

    void swap(TreeNode* a, TreeNode* b) {
        int temp;
        temp = a->val;
        a->val = b->val;
        b->val = temp;
    }
};