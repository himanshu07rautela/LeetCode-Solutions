class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>time;
        for(int i=0;i<timePoints.size();i++){
            // lets extract first
          int hour = stoi(timePoints[i].substr(0, 2));
          int minutes=stoi(timePoints[i].substr(3,2));
          int minutes1=hour*60+minutes;
          time.push_back(minutes1);                      
        }
       sort(time.begin(), time.end());
        
        int ans = INT_MAX;
        
       
        for(int i = 0; i < time.size() - 1; i++) {
            ans = min(ans, time[i+1] - time[i]);
        }
        
        // Handle the circular difference between the last and first time points
        int circularDifference = 1440 - time.back() + time[0]; 
        ans = min(ans, circularDifference);
        return ans;

    }
};