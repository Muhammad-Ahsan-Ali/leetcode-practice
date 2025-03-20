 
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
          if (!root)
            return TreeNode* newRoot(val) ;

        TreeNode* cur = root;
        TreeNode* prev = cur;

        TreeNode* node = new TreeNode(val);
        while (cur)
        {
            prev = cur;
              if (cur->val > key) {
                 cur = cur->left;
            } else {
                 cur = cur->right;
            }
        }
if(prev->val > val ) prev->right=node;
else prev->left=node;

    }
};