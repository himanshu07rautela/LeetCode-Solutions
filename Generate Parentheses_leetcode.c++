class Solution {
public:
    void solve(int n, int open,int close, vector<char>&a,vector<string>&ans){
        if(a.size()==2*n){
            string s1(a.begin(),a.end());
            ans.push_back(s1);
            return;
        }
        if(open<n){
            a.push_back('(');
            solve(n,open+1,close,a,ans);
            a.pop_back();
        }
        if(close<open){
            a.push_back(')');
            solve(n,open,close+1,a,ans);
            a.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        vector<char>a;
        solve(n,0,0,a,ans);
        return ans;
    }
};