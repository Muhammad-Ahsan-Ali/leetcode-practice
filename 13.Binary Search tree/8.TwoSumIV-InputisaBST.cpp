
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {

        if (!root)
            return false;

        stack<TreeNode*> sl;
        stack<TreeNode*> sr;

        TreeNode* left = root;
        TreeNode* right = root;

        while (1) {

            while (left) {
                sl.push(left);
                left = left->left;
            }

            while (right) {
                sr.push(right);
                right = right->right;
            }

            if (sl.empty() || sr.empty())
                break;

            left = sl.top();
            right = sr.top();

            if (left == right)
                return false;

            if (left->val + right->val == k)
                return true;
            else if (left->val + right->val < k) {
                left = left->right;
                right = nullptr;
                sl.pop();
            } else if (left->val + right->val > k) {
                left = nullptr;
                right = right->left;
                sr.pop();
            }
        }
        return false;
    }
};