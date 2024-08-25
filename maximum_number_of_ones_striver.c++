class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // its simple O(n) and O(1) should be the target 
        int gans=0;
        int k=0;//showing ki no there is no 1
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1 && k==0){
                ans=1;
                gans=max(gans,ans);
                k=1;
            }else if(nums[i]==1 && k==1){
                ans++;
                gans=max(gans,ans);
                k=1;
            }else{
                ans=0;
                k=0;
            }

        }
        return gans;
    }
};