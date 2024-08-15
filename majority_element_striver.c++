class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // we'll use majority vote algorithm boyle moore 
        // consider a candidate first
        int candi=nums[0];
        int count=1;
        for(int i=1;i<nums.size();i++){
            if(candi==nums[i]){
                count++;
            }else{
                count--;
            }
            if(count==0){
                candi=nums[i];
                count=1;
            }
        }
        // till the end of this process we would have found out whos is our candidate
        // so lets verify it
        int ans=0;
        for(int i=0;i<nums.size();i++ ){
            if(candi==nums[i]){
                ans++;
            }
        }
        if(ans>(nums.size()/2)){
            return candi;
        }else{
            return -1;
        }

    }
};