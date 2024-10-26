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
   //morris inordeer traversal
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode*p=root;
        vector<int>ans;
        while(p!=NULL){
            if(p->left==NULL){
                ans.push_back(p->val);
                p=p->right;
            }else{
                TreeNode*q=p->left;
                while(q!=NULL &&q->right!=NULL && q->right!=p){
                      q=q->right;
                }
                if(q->right==NULL){
                    ans.push_back(p->val);
                    q->right=p;
                    p=p->left;
                    
                }else{
                    q->right=NULL;
                    p=p->right;
                }
            }
        }
        return ans;
    }
};