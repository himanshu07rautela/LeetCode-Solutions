class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        int ans=INT_MAX;
        while(s<=e){
            // check initially
            if(nums[s]<nums[e]){
                ans=min(ans,nums[s]);
                return ans;
            }
            int mid=s+(e-s)/2;
            ans=min(ans,nums[mid]);
            if(nums[mid]>=nums[s]){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return ans;;
    }
};