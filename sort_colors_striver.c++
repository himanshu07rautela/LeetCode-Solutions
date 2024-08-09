class Solution {
public:
    void sortColors(vector<int>& nums) {
        // without sort function i am thinking 2 pointers
        // there is like some way of doing it in pointer way but here is a unique appoach
        int ones=0;
        int zeros=0;
        int twos=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zeros++;
            }else if(nums[i]==1){
                ones++;
            }else{
                twos++;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(zeros>0){
                nums[i]=0;
                zeros--;
                continue;
            }
            if(ones>0){
                nums[i]=1;
                ones--;
                continue;
            }
            if(twos>0){
                nums[i]=2;
                twos--;
                continue;
            }
        }
        return;
    }
};