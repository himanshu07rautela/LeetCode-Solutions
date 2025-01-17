/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        while(root!=NULL){
            if(root->val>=min(p->val,q->val ) && root->val<=max(p->val,q->val)){
                return root;
            }else if(root->val<min(p->val,q->val) ){
                root=root->right;
            }else if(root->val>max(p->val,q->val)){
                root=root->left;
            }
        }
        return NULL;
    }
};