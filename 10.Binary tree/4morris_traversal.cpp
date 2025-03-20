void preOrder(TreeNode* root) {

while(root)
{

if(root->left == nullptr)
{

cout<<root->val;
root =root->right;

}
else{
TreeNode* cur=root->left;
while(cur->right && cur->right != root)
{
cur=cur->right;
}

if(cur->right == nullptr )
{
    cur->right= root;
    cout<<root->data;
    root=root->left;
}
else{
cur->right=nullptr;
root=root->right;
}

}



}



}

