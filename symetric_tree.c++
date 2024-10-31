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
    bool solve(TreeNode*a,TreeNode*b){
        if(a==NULL && b!=NULL || a!=NULL && b==NULL){
            return false;
        }
        if(a==NULL && b==NULL){
            return true;
        }
        if(a->val ==b->val){
            bool a1=solve(a->left ,b->right);
            bool a2=solve(a->right,b->left);
            return a1 && a2;
        }else{
            return false;
        }
    }
    bool isSymmetric(TreeNode* root) {
        // i have a way which is to just compare the left and right sides
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        return solve(root->left,root->right);

    }
};