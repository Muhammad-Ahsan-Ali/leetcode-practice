

#include <iostream>
#include <algorithm>
using namespace std;







class Solution {
public:


int hlprDmtrOfBTree(TreeNode* root ,int & diameter){

if(!root) return 0;

int lh =hlprDmtrOfBTree(  root->left ,diameter);
int rh =hlprDmtrOfBTree(  root->right ,diameter);

diameter=max(diameter,lh+rh);

return 1+ max(lh,rh);
}

    int diameterOfBinaryTree(TreeNode* root) {

        int diameter=0;
        hlprDmtrOfBTree(  root ,diameter);

        return diameter;
    }
};



int main(

    return 0;
)