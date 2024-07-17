class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int start = 0;
        int totalGas = 0;
        int currentGas = 0;

        for (int i = 0; i < n; ++i) {
            totalGas += gas[i] - cost[i];
            currentGas += gas[i] - cost[i];

            
            if (currentGas < 0) {
                start = i + 1;
                currentGas = 0; 
            }
        }


        return totalGas >= 0 ? start : -1;
    }
};
// the thing is ki eske just neeche mene ek unoptimised TLE bhi kiya tha