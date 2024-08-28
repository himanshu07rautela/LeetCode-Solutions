class Solution {
public:
    void solve(vector<int>&nums,vector<int>&s,vector<vector<int>>&ans,unordered_map<int,bool>&mp){
        if(s.size()==nums.size()){
            ans.push_back(s);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(mp[i]!=true){
                mp[i]=true;
                s.push_back(nums[i]);
                solve(nums,s,ans,mp);
                mp[i]=false;
                s.pop_back();
            }

        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        unordered_map<int,bool>mp;
        vector<int>s;
        solve(nums,s,ans,mp);
        return ans;
        
    }
};