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
    void solve(TreeNode*&root,vector<TreeNode*>&arr){
        if(root==NULL){
            return;
        }
        arr.push_back(root);
        
        solve(root->left,arr);
        solve(root->right,arr);
        
    }
    void flatten(TreeNode* root) {
        
        vector<TreeNode*>arr;
        TreeNode*ans=new TreeNode(-1);
        solve(root,arr);
        for(int i=0;i<arr.size();i++){
            ans->left=NULL;
            ans->right=arr[i];
            ans=arr[i];
        }
        return ;
      
    }
};