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
        queue<TreeNode*>q1;
        q1.push(root);
        unordered_map<TreeNode*,TreeNode*>mp;
        mp[root]=NULL;
        while(!q1.empty()){
            int n=q1.size();
            for(int i=0;i<n;i++){
                TreeNode*t=q1.front();
                q1.pop();
                if(t->left){
                    mp[t->left]=t;
                    q1.push(t->left);
                }
                if(t->right){
                    q1.push(t->right);
                    mp[t->right]=t;
                }
            }
        }
        vector<TreeNode*>arr1;
        vector<TreeNode*>arr2;
        TreeNode*t1=p;
        TreeNode*t2=q;
        while(t1!=NULL){
            arr1.push_back(t1);
            t1=mp[t1];
        }
        while(t2!=NULL){
            arr2.push_back(t2);
            t2=mp[t2];
        }
        unordered_map<TreeNode*,bool>b1;
        unordered_map<TreeNode*,bool>b2;
        for(int i=0;i<arr1.size();i++){
            b1[arr1[i]]=true;
        }
        for(int i=0;i<arr2.size();i++){
            b2[arr2[i]]=true;
        }
        if(b1[q]==true){
            return q;
        }
        if(b2[p]==true){
            return p;
        }
        for(int i=0;i<arr1.size();i++){
            if(b2[arr1[i]]==true){
                return arr1[i];
            }
        }
        return NULL;
    }
};