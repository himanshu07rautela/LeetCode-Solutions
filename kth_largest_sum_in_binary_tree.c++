/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     long long val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long>sums;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            long long sum=0;
            long long n=q.size();
            for(long long i=0;i<n;i++){
                TreeNode*a=q.front();
                q.pop();
                sum=sum+a->val;
                if(a->left!=NULL){
                    q.push(a->left);
                }
                if(a->right!=NULL){
                    q.push(a->right);
                }
            }
            sums.push_back(sum);
        }
        sort(sums.begin(),sums.end());
        reverse(sums.begin(),sums.end());
        if(k>sums.size()){
            return -1;

        }
        return sums[k-1];

    }
};