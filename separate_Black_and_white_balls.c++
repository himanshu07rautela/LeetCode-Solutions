class Solution {
public:
    long long minimumSteps(string s) { // Use long long for ans
        long long ans = 0;  // Change ans to long long
        int nones = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                nones++;  // Count the number of '1's encountered
            } else if (s[i] == '0') {
                ans += nones;  // Add the count of '1's before the '0'
            }
        }
        
        return ans;  // Return the total swaps
    }
};
