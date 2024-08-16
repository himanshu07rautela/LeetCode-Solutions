class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int max_length=0;
        if(nums.size()==0 || nums.size()==1){
            return nums.size();
        }
        // sort(nums.begin(),nums.end());
        set<int>s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        vector<int>nums1(s.begin(),s.end());
        for(int i=0;i<nums1.size()-1;i++){
            if(s.find(nums1[i]-1)==s.end()){
            int count=1;
            int s=i+1;
            while(s<nums1.size() && nums1[s] == nums1[s-1]+1){
                count++;
                s++;
            }
            max_length=max(max_length,count);
            }
        }
        if(max_length==0){
            return 1;
        }
        return max_length;
    }
};