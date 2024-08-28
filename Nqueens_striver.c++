class Solution {
public:
// lets go its actually pretty good question and much frequently asked
// in interviews
    bool issafe(vector<vector<char>>board, int row, int col){
        // first check in the col below
        for(int i=0;i<col;i++){
            if(board[row][i]=='Q'){
                return false;

            }
        }
        // lets check diagonally
        for(int i=row,j=col;i>=0&&j>=0;i--,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        for(int i=row,j=col;i<board.size()&&j>=0;i++,j--){
            if(board[i][j]=='Q'){
                return false;
            }

        }
        return true;
    }
    void addanswer(vector<vector<char>>&board,vector<vector<string>>&ans){
        vector<string>ans1;
        for(int i=0;i<board.size();i++){
            string a(board[i].begin(),board[i].end());
            ans1.push_back(a);
        }
        ans.push_back(ans1);
    }
    void solve(int n , vector<vector<char>>&board,vector<vector<string>>&ans, int row, int col){
        if(col==n){
            addanswer(board,ans);
            return;
        }
        for(int i=0;i<n;i++){
            if(issafe(board,i,col)){
                board[i][col]='Q';
                solve(n,board,ans,row,col+1);
                board[i][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n){
        vector<vector<char>>board(n,vector<char>(n,'.'));
        vector<vector<string>>ans;
        solve(n,board,ans,0,0);
        return ans;
        
    }
};