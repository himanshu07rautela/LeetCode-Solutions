class Solution {
public:
    int search(vector<int>& nums, int target) {
        // first we'll find the pivot and then we'll find the element in 2 separate arrays
        // neeche wala pivot nikalenge
        if(nums[0]==target){
            return 0;
        }
        if(nums[nums.size()-1]==target){
            return nums.size()-1;
        }
       
        int s=0;
        int e=nums.size()-1;
         while (s < e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] > nums[e]) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }
        int pivot=s;
        // lets just find out in both the halves
        s=0;
        e=pivot-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]>target){
                
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        s=pivot;
        e=nums.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]>target){
                
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return -1;
    }
};