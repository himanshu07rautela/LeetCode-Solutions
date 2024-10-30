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
    void solve(TreeNode*root, int n, int&ans){
        if(root->left==NULL && root->right==NULL){
            n++;
            ans=max(n,ans);
            n--;
            return;
        }
        if(root->left){
            solve(root->left,n+1,ans);
        }
        if(root->right){
            solve(root->right,n+1,ans);
        }
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right==NULL){
            return 1;
        }
        int ans=-1;
        solve(root,0,ans);
        return ans;
    }
};