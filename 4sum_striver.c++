class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        int n = nums.size();
        
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicate elements
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; // Skip duplicate elements
                int num1 = nums[i];
                int num2 = nums[j];
                int s = j + 1;
                int e = n - 1;
                
                while (s < e) {
                   long long sum = (long long)nums[i] + nums[j] + nums[s] + nums[e];
                    if (sum == target) {
                        ans.insert({num1, num2, nums[s], nums[e]});
                        s++;
                        e--;
                    } else if (sum < target) {
                        s++;
                    } else {
                        e--;
                    }
                }
            }
        }
        vector<vector<int>>ans1(ans.begin(),ans.end());
        return ans1;
    }
    // we can avoid conditions of if cause we're using set
    // but its much better time complexity wise
};
