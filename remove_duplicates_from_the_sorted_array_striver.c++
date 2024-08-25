class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // int totalsize=nums.size();
        // set<int>s;
        // for(int i=0;i<totalsize;i++){
        //     s.insert(nums[i]);
        // }
        // vector<int>nums1(s.begin(),s.end());
        // for(int i=0;i<nums1.size();i++){
        //     nums[i]=nums1[i];
        // }
        // return nums1.size();
        // last one is O(N log (n)) and O(N) both space and time complexity
        int uniqueindex=0;
        int last=-1001;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=last){
                nums[uniqueindex]=nums[i];
                uniqueindex++;
                last=nums[i];
            }
        }
        return uniqueindex;
    // O(n) and o(1) which is significantly better
    }
};