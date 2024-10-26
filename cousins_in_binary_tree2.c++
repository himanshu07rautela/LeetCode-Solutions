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
    TreeNode* replaceValueInTree(TreeNode* root) {
        // same depth with the different parent;
        // simply meanswe have to associate each one with depth and parent
        // plan is ki we will first kind of get the vector
        // of ans
        unordered_map<TreeNode*,TreeNode*>mp;
        mp[root]=NULL;
        // we will make unordered_map which has a sum of same parent nodes
        unordered_map<TreeNode*,int>mp2;
        mp[NULL]=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode*a=q.front();
                q.pop();
                int sum=0;
                if(a->left!=NULL){
                    q.push(a->left);
                    mp[a->left]=a;
                    sum=sum+a->left->val;
                }
                if(a->right!=NULL){
                    q.push(a->right);
                    mp[a->right]=a;
                    sum=sum+a->right->val;
                }
                mp2[a]=sum;
            }
        }//mapping is done my friends
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<TreeNode*>arr;
            int sum=0;
            for(int i=0;i<n;i++){
                TreeNode*a=q.front();
                q.pop();
                arr.push_back(a);
                sum=sum+a->val;
                if(a->left!=NULL){
                    q.push(a->left);
                }
                if(a->right!=NULL){
                    q.push(a->right);
                }
            }
            vector<int>arr2(n);
            for(int i=0;i<n;i++){
                arr2[i]=sum-mp2[mp[arr[i]]];
            }
            for(int i=0;i<n;i++){
                arr[i]->val=arr2[i];
            }

        }
        root->val=0;
        return root;

        

    }
};