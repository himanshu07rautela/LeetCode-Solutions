class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // we have to find the 1st pivot from the right 
        int i=nums.size()-2;
        while(i>=0 && nums[i]>=nums[i+1]){
            i--;
        }
        // now we have a pivot; jo 2 me hai

        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }
            
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};