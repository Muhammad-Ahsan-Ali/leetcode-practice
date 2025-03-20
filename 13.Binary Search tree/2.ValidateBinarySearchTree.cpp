#include  <iostream> 
#include <algorithm>
using namespace std

class Solution {
public:
    bool isValidBST(TreeNode* root) 
    {
        if (root == nullptr) return true;
        if(root->val > root->left && root->val < root->right ){
      bool leftValid=  isValidBST(root->left):
        bool rightValid= isValidBST(root->right):
        }
        if(leftValid && rightValid )
        {
            return true;
        }
else{
    return false;
}


    }
};


int main ()
{
   return 0;
}


