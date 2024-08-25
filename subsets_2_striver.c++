class Solution {
public:
    void solve(vector<int>& nums, vector<int>& a, int index, vector<vector<int>>& ans) {
        if (index >= nums.size()) {
            ans.push_back(a);
            return;
        }
        // Include the current element
        a.push_back(nums[index]);
        solve(nums, a, index + 1, ans);
        
        // Backtrack and exclude the current element
        a.pop_back();
        solve(nums, a, index + 1, ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> a;
        
        // Generate all subsets
        solve(nums, a, 0, ans);
        
        // Sort each subset to handle duplicates
        for(auto& subset : ans) {
            sort(subset.begin(), subset.end());
        }
        
        // Remove duplicates using unique and erase
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        
        // Sort based on size and lexicographical order
        sort(ans.begin(), ans.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a.size() != b.size()) return a.size() < b.size();
            return a < b;
        });
        
        return ans;
    }
};
