class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int imax = 0;
        int jmax = n - 1;
        // Step 1: Find the longest non-decreasing prefix
        while (imax < n - 1 && arr[imax] <= arr[imax + 1]) {
            imax++;
        }

        // If the entire array is already sorted
        if (imax == n - 1) {
            return 0;
        }

        // Step 2: Find the longest non-decreasing suffix
        while (jmax > 0 && arr[jmax] >= arr[jmax - 1]) {
            jmax--;
        }

        // Step 3: Calculate the minimum length to remove
        int ans = min(n - imax - 1, jmax);  // Removing prefix or suffix entirely

        // Step 4: Use two pointers to merge the sorted parts
        int i = 0;
        int j = jmax;
        while (i <= imax && j < n) {
            if (arr[i] <= arr[j]) {
                ans = min(ans, j - i - 1);
                i++;
            } else {
                j++;
            }
        }
        return ans;
    }
};