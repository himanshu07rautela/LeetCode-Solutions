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
    void solve(TreeNode*root,vector<TreeNode*>&arr){
        if(root==NULL){
            return ;
        }
        arr.push_back(root);
        solve(root->left,arr);
        solve(root->right,arr);
    }
    void flatten(TreeNode* root) {
        if(root==NULL){
            return;
        }
        vector<TreeNode*>arr;
        solve(root,arr);
        root->right=NULL;
        root->left=NULL;
        TreeNode*prev=root;
        for(int i=1;i<arr.size();i++){
            TreeNode*a=arr[i];
            prev->right=a;
            prev->left=NULL;
            prev=a;

        }
        prev->left=NULL;
        prev->right=NULL;
        return ;
    }
};