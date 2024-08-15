class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;//first one holds number value and second one holds the index
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i;
        }
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            int curr=nums[i];
            int rem=target-nums[i];
            if(mp.find(rem)!=mp.end() && mp[rem]!=i){
                ans.push_back(mp[rem]);
                ans.push_back(i);
                return ans;
            }
        }
        return ans;
    }
};