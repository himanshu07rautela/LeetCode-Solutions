class Solution {
public:
    void solve(vector<int>& candidates, int target, int sum, int index, vector<int>& arr, vector<vector<int>>& ans) {
        if (sum == target) {
            ans.push_back(arr);
            return;
        }
        if (sum > target || index >= candidates.size()) {
            return;
        }
        for (int i = index; i < candidates.size(); ++i) {
            if (i > index && candidates[i] == candidates[i - 1]) continue; // Skip duplicates
            arr.push_back(candidates[i]);
            solve(candidates, target, sum + candidates[i], i + 1, arr, ans); // Move to the next index
            arr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        sort(candidates.begin(), candidates.end()); // Sort the candidates to handle duplicates
        solve(candidates, target, 0, 0, arr, ans);
        return ans;
        // it is good beqacuse it avoids the sue of set in this 
    }
};