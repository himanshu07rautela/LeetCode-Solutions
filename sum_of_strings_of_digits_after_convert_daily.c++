class Solution {
public:
    int getLucky(string s, int k) {
        // Convert string to a string of numbers
        string nums;
        for (char c: s) {
            nums += to_string(c - 'a' + 1);
        }
        
        for (int i = 0; i < k; i++) {
            int sum = 0;
            for (char c : nums) {
                sum += (c - '0');
            }
            string newnums;
            while (sum != 0) {
                int digit = sum % 10;
                newnums += to_string(digit);
                sum /= 10;
            }
            reverse(newnums.begin(), newnums.end()); // Reverse the string to maintain correct order
            nums = newnums;
        }
        
        // Calculate the final sum of digits
        int ans = 0;
        for (char c : nums) {
            ans=ans*10+(c-'0');
        }
        return ans;
    }
};
