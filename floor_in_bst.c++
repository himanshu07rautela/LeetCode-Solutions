#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void solve(TreeNode<int> * root,int x,int&ans){
    if(root==NULL){
        return;
    }
    solve(root->left,x,ans);
    if(root->val<=x){
        ans=root->val;
    }
    solve(root->right,x,ans);
    
}
int floorInBST(TreeNode<int> * root, int X)
{
    // greatest value of x , which is smaller than or equal to x
    int ans=0;
    solve(root,X,ans);
    return ans; 
}