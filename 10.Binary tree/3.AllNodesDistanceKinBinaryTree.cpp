

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution {
public:


TreeNode* findTarget(TreeNode* root, TreeNode* target,map<TreeNode*, TreeNode*>& parntMp)
{
if(!root) return nullptr;
if(root==target) return root;

parntMp[root->left]=root;
    TreeNode* leftResult = findTarget(root->left, target,parntMp);
    if (leftResult) return leftResult; 
parntMp[root->right]=root;
    return findTarget(root->right,  target,parntMp);
}


void distKHelpr(TreeNode* root, int trvrs, int k, vector<int>& arr, map<TreeNode*, TreeNode*>& parntMp, set<TreeNode*>& visited) {
    if (!root || visited.find(root) != visited.end()) return; 

    visited.insert(root); 
    if (trvrs == k) {
        arr.push_back(root->val);       return;
    }

    // Recursive calls to parent, left, and right children
    if (parntMp[root]) distKHelpr(parntMp[root], trvrs + 1, k, arr, parntMp, visited);
    distKHelpr(root->left, trvrs + 1, k, arr, parntMp, visited);
    distKHelpr(root->right, trvrs + 1, k, arr, parntMp, visited);
}

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

map<TreeNode*, TreeNode*> parntMp;
parntMp[root]=nullptr;
TreeNode*  trgtNode=findTarget(root,  target,parntMp);
vector<int> output;
set<TreeNode*> visited;
distKHelpr(trgtNode,0,k,output,parntMp,visited);

return output;

    }
};




int main(

    return 0;
)