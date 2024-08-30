class Solution {
  public:
    void solve(vector<vector<int>> &mat,vector<vector<int>>&curr_path,int i , int j, vector<char>&path,vector<string>&ans){
        
        if(i==mat.size()-1 && j==mat[0].size()-1){
            string path1(path.begin(),path.end());
            ans.push_back(path1);
            return;
        }
        // going right
        if(i!=mat.size()-1 && curr_path[i+1][j]==0 &&  mat[i+1][j]==1){
            curr_path[i+1][j]=1;
            path.push_back('D');
            solve(mat,curr_path,i+1,j,path,ans);
            path.pop_back();
            curr_path[i+1][j]=0;
        }
        if(i!=0 &&curr_path[i-1][j]==0 && mat[i-1][j]==1){
            curr_path[i-1][j]=1;
            path.push_back('U');
            solve(mat,curr_path,i-1,j,path,ans);
             path.pop_back();
            curr_path[i-1][j]=0;
        }
        if(j!=mat[0].size()-1 && curr_path[i][j+1]==0 && mat[i][j+1]==1){
            curr_path[i][j+1]=1;
            path.push_back('R');
            solve(mat,curr_path,i,j+1,path,ans);
            path.pop_back();
            curr_path[i][j+1]=0;
        }
        if(j!=0 && curr_path[i][j-1]==0 && mat[i][j-1]==1){
            curr_path[i][j-1]=1;
            path.push_back('L');
            solve(mat,curr_path,i,j-1,path,ans);
            path.pop_back();
            curr_path[i][j-1]=0;
        }
        return;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        if(mat[0][0]==0){
            vector<string>ans;
            return ans;
        }
        vector<vector<int>>curr_path(mat.size(),vector<int>(mat[0].size(),0));
        curr_path[0][0]=1;
        vector<char>path;
        vector<string>ans;
        solve(mat,curr_path,0,0,path,ans);
        return ans;
        
        
        
    }
};