class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        // its medium so it expects us to do it in less than O(n^2);
        // we can have a unordered_map and we can check its size to see if 
        // all are distinct or not
        long long ans=0;
        unordered_map<int,int>mp;
        long long sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
            mp[nums[i]]++;
        }
        if(mp.size()==k){
            ans=max(ans,sum);
        }
        
        for(int i=k;i<nums.size();i++){
            int removed=nums[i-k];
            mp[removed]--;
            sum=sum-removed;
            if(mp[removed]==0){
                mp.erase(removed);
            }
            mp[nums[i]]++;
            sum=sum+nums[i];
            if(mp.size()==k){
                ans=max(ans,sum);
            }
        }
        return ans;


    }
};