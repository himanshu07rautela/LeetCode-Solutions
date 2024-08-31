class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string newa = a;
        int count = 1;

        // Build the string newa with repetitions of a until it is long enough
        while (newa.size() < b.size()) {
            newa += a;
            count++;
        }

        // Check if b is in the current newa
        if (newa.find(b) != string::npos) {
            return count;
        }

        // Add one more repetition to handle overlap cases
        newa += a;
        count++;
        if (newa.find(b) != string::npos) {
            return count;
        }

        return -1; // If b is not found
    }
};
