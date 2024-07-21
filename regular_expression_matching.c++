class Solution {
public:
    bool solve(string s,string p,int i, int j,vector<vector<int>>&dp){
        if(i>=s.size() && j>=p.size()){
            return true;
        }
        if(i<s.size() && j>=p.size()){
            return false;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i>=s.size() && j<p.size()){
            for(int ii = j; ii < p.size(); ii++)
            {
                if((p[ii] == '*') || (ii + 1 < p.size() && p[ii + 1] == '*')) continue;
                else return false;
            }
            return true;
        }
        // according to precedence
        if(j+1<p.size() && p[j+1]=='*'){
            // preceding
            bool ans1=solve(s,p,i,j+2,dp);//zero occurence easy man
            bool ans2=false;
            if(s[i]==p[j] || p[j]=='.'){
                ans2=solve(s,p,i+1,j,dp);
            }
            return dp[i][j]= ans1 || ans2;
        }
        if(s[i]==p[j] || p[j]=='.'){
            return dp[i][j]= solve(s,p,i+1,j+1,dp);
        }
        return dp[i][j]=false;
    }
    // * ke peeche wale ko 0 ya kitni bhi baar use kar sakte hai
    // from 0 to n and 0 to m
    

    bool isMatch(string s, string p) {
        // convert to memoization
        vector<vector<int>>dp(s.size()+1,vector<int>(p.size()+1,-1));
        return solve(s,p,0,0,dp);
    }
};