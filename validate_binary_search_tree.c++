/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //one way is by using the fact that , inorder is sorted 
    //but here is the way
    bool solve(TreeNode*root , long long l , long long  h){
        if(root==NULL){
            return true;
        }
        if(root->val<=l ||root->val>=h ){
            return false;
        }
        int val=root->val;
        bool lefti=solve(root->left,l,val);
        bool righti=solve(root->right,val,h);
        return lefti && righti;
    }
    bool isValidBST(TreeNode* root) {
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        return solve(root,LLONG_MIN,LLONG_MAX);
    }
};