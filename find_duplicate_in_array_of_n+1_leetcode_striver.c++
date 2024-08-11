class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // we can use unordered_maps
        unordered_map<int,bool>mp;
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]==true){
                return nums[i];
            }
            mp[nums[i]]=true;
        }
        return -1;
    }
};