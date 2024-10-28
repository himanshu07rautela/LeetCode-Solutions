class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        // its very simple 
        int ans=0;
        unordered_map<int,bool>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=true;
        }
        
        for(int i=0;i<nums.size();i++){
            int n=nums[i];
            int ans1=0;
            while(mp.find(n)!=mp.end() && mp[n]==true){
                ans1++;
                if (n > sqrt(INT_MAX)) break; // Check to prevent overflow
                n = n * n;
                
            }

            ans=max(ans,ans1);
        }
        if(ans==0 || ans==1){
            return -1;
        }
        return ans;
    }
};