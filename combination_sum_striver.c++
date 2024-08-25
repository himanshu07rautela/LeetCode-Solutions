class Solution {
public:
    void solve(vector<int>&candidates,int target,int index, int sum,vector<int>a,vector<vector<int>>&ans){
       
        if(sum==target ){
            ans.push_back(a);
            return;
        }
        if(sum>target || index>=candidates.size()){
            return;
        }
        a.push_back(candidates[index]);
        solve(candidates,target,index,sum+candidates[index],a,ans);
        a.pop_back();
        solve(candidates,target,index+1,sum,a,ans);
        return;

    }
     
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      
        vector<vector<int>>ans;
        vector<int>a;
        solve(candidates,target,0,0,a,ans);
        // vector<vector<int>>ans1(ans.begin(),ans.end());
        return ans;
    }
};