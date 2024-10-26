/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
void solvein(TreeNode*root,vector<int>&ans){
    if(root==NULL){
        return;
    }
    solvein(root->left,ans);
    ans.push_back(root->data);
    solvein(root->right,ans);
    
}
void solvepre(TreeNode*root,vector<int>&ans){
    if(root==NULL){
        return;
    }
    
    ans.push_back(root->data);
    solvepre(root->left,ans);
    solvepre(root->right,ans);
    
}
void solvepost(TreeNode*root,vector<int>&ans){
    if(root==NULL){
        return;
    }
    solvepost(root->left,ans);
    solvepost(root->right,ans);
    ans.push_back(root->data);
    
}
vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    vector<vector<int>>ans;
    vector<int>ans1;
    vector<int>ans2;
    vector<int>ans3;
    solvein(root,ans1);
    solvepre(root,ans2);
    solvepost(root,ans3);
    ans.push_back(ans1);
    ans.push_back(ans2);
    ans.push_back(ans3);
    return ans;


}