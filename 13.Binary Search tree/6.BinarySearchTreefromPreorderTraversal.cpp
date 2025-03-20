class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {   
           int min=INT_MIN;
          int max=INT_MAX;
    queue<int> preorderQ;
    for (int val : preorder) {
        preorderQ.push(val);
    }
          return buildTree( preorder , max , min)
    }    

TreeNode* buildTree(queue<int>& preorder ,int max ,int min)
{

while(!preorder.empty() && preorder.front()<max && preorder.front()>min )
{
    int val=preorder.front();
    preorder.pop();
    TreeNode* node= new TreeNode(val);
    
    node->left= buildTree(preorder,val,max);
    node->right=  buildTree(preorder,min,val) ;
return node;
}

return nullptr;
}


};