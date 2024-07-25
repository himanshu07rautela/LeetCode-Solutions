class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // we just have to find two distinct positions of k;
        // 
        unordered_map<int,int>mp;
        // if abs(i-j)<=k
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])==mp.end()){
                mp[nums[i]]=i;
            }else{
                int first=mp[nums[i]];
                int second=i;
                if(abs(first-second)<=k){
                    return true;
                }else{
                    mp[nums[i]]=i;
                }
            }
        }
        return false;
    }
};