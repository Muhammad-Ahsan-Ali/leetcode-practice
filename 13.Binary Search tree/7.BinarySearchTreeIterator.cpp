#include  <iostream> 
#include <algorithm>
using namespace std


class BSTIterator {
public:
    TreeNode* cur;
    BSTIterator(TreeNode* root) { cur = root; }

    int next() {
        int val;
        while (cur) {
            if (!cur->left) {
                val = cur->val;
                cur = cur->right;
                return val;
            } else {
                TreeNode* pred = cur->left;
                while (pred->right && pred->right != cur) {
                    pred = pred->right;
                }
                if (pred->right) {
                    pred->right = nullptr;
                    val = cur->val;
                    cur = cur->right;
                    return val;
                } else {
                    pred->right = cur;
                    cur = cur->left;
                }
            }
        }
                            return val;
    }

    bool hasNext() {
        while (cur) {
            if (!cur->left) {
                return true;
            } else {
                TreeNode* pred = cur->left;
                while (pred->right && pred->right != cur) {
                    pred = pred->right;
                }

                if (pred->right) {
                         return true;
                } else {
                    pred->right = cur;
                    cur = cur->left;
                }
            }
        }
        return false;
    }
};






int main ()
{
   return 0;
}
