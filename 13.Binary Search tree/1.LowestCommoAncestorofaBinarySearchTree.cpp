#include  <iostream> 
#include <algorithm>
using namespace std

class Solution {
public:
 TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
 {
TreeNode*cur= root;

while(q->val > cur->val &&  p->val < cur->val)
{
cur=cur->left;
}

return cur;
  }
};


int main ()
{
   return 0;
}
