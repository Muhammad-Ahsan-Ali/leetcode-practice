#include <iostream>
#include <algoritm>
using namespace std


class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* cur =root;
        int elmntIndx=0;
        stack<TreeNode*> s;
    s.push(root);
        while(1)
        {
while(cur){    
s.push(cur);
cur=cur->left;
}
cur=s.top();
elmntIndx++;
if(elmntIndx==k) return cur->val;
cur=cur->right;
        }
    }
};


class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* cur = root;
        int count = 0;
        int ans=root->val;
        while (cur) {
            if (!cur->left) {
                count++;
                if (count == k) return ans=cur->val;
                cur = cur->right;
            } else {
                TreeNode* pred = cur->left;
                while (pred->right && pred->right != cur) {
                    pred = pred->right;
                }
                
                if (!pred->right) {
                    pred->right = cur;
                    cur = cur->left;
                } else {
                    pred->right = nullptr;
                    count++;
                    if (count == k)  ans=cur->val;
                    cur = cur->right;
                }
            }
        }
        
        return ans;  
    }
};



class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int ans = 0;

        while (root) {

            if (root->left == nullptr) {

                count++;
                if (count == k)
                    ans = root->val;
                root = root->right;
            } else {
                TreeNode* cur = root->left;
                while (cur->right && cur->right != root) {
                    cur = cur->right;
                }

                if (cur->right == nullptr) {
                    cur->right = root;
                    root = root->left;
                } else {

                    cur->right = nullptr;
                    count++;
                    if (count == k)
                        ans = root->val;
                    root = root->right;
                }
            }
        }
        return ans;
    }
};


int main(){

    return 0;
}