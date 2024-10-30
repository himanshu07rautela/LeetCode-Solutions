
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
    // ek baar right jao ek baar left uar maximum depth nikalo aur 
    // difference check kar lo
    void mxidep(TreeNode*root, int n , int&ans){
         if (root == NULL) return; // Check for null
    if (root->right == NULL && root->left == NULL) {
        n++;
        ans = max(n, ans);
        n--;
        return;
    }
        if(root->left){
            mxidep(root->left,n+1,ans);
        }
        if(root->right){
            mxidep(root->right,n+1,ans);
        }
    }
    bool solve(TreeNode*root){
        if(root==NULL){
            return true;
        }
        int ans1=0;
        int ans2=0;
        mxidep(root->left,0,ans1);
        mxidep(root->right,0,ans2);

        if(abs(ans1-ans2)>1){
            return false;
        }else{
            return solve(root->left) && solve(root->right);
        }
    }
    bool isBalanced(TreeNode* root) {
        return solve(root);
    }
};