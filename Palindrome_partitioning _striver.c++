class Solution {
public:
    bool check(string s,int start, int end){
        if(end==start){
            return true;
        }
        while(start<=end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void solve(string s , int start , vector<string>a,vector<vector<string>>&ans){
        if(start >=s.size()){
            ans.push_back(a);
            return;
        }
        for(int i=start;i<s.size();i++){
            if(check(s,start,i)){
                a.push_back(s.substr(start,i-start+1));
                solve(s,i+1,a,ans);
                a.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        // we have to partition it in such a way that each partition is 
        // palindrome, wow just a great question this backtrack series has been quite a banger
        vector<string>a;
        vector<vector<string>>ans;
        solve(s,0,a,ans);
        return ans;


    }
};