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
    //we will just make pair and  from 1st and last and keep going forward and backward
    void solve(TreeNode*root,vector<int>&ans){
        if(root==NULL){
            return;
        }
        solve(root->left,ans);
        ans.push_back(root->val);
        solve(root->right,ans);
        return;
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>ans;
        solve(root,ans);
        int s=0;
        int e=ans.size()-1;
        while(e>s){
            if(ans[s]+ans[e]==k){
                return true;
            }else if(ans[s]+ans[e]>k){
                e--;
            }else{
                s++;
            }
        }
        return false;
        
    }
};