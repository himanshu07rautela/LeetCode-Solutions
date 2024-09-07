/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool solve(TreeNode*root,vector<int>&ll, int i){
        if(i>=ll.size()){
            return true;
        }
        if(root==NULL){
            return false;
        }
        if(root->val==ll[i]){
            bool left=solve(root->left,ll,i+1);
            bool right=solve(root->right,ll,i+1);
            return left||right;
        }else{
            return false;
        }

    }
    bool totalsolve(TreeNode*root,vector<int>&ll){
        if(root==NULL){
            return false;
        }
        if(solve(root,ll,0)){
            return true;
        }
        return totalsolve(root->left,ll)||totalsolve(root->right,ll);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        // corre
        vector<int>ll;
        ListNode*p=head;
        
        while(p!=NULL){
            int d=p->val;
            ll.push_back(d);
            p=p->next;
        }
        
        return totalsolve(root,ll);
        
    }
};