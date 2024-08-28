class Solution {
public:
    void solve(int n,int k,vector<bool>&a,vector<char>&s,vector<vector<char>>&ans){
        if(s.size()==n){
            ans.push_back(s);
            return;
        }
        if(ans.size()==k){
            return;
        }
        for(int i=1;i<=n;i++){
            if(a[i]!=true){
                char c='0'+i;
                s.push_back(c);
                a[i]=true;
                solve(n,k,a,s,ans);
                a[i]=false;
                s.pop_back();
            }
        }
        return;

    }
    string getPermutation(int n, int k) {
        vector<bool>a(n+1,false);
        vector<vector<char>>ans;
        vector<char>s;
        solve(n,k,a,s,ans);
        vector<char>ans1=ans[k-1];
        string ans2(ans1.begin(),ans1.end());
        return ans2;
        
    }
};