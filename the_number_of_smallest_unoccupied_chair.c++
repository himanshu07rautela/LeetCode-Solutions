#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        for (int i = 0; i < times.size(); i++) {
            times[i].push_back(i);
        }
        priority_queue<int, vector<int>, greater<int>> currseat;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>occupied;
        for(int i=0;i<times.size();i++){
            currseat.push(i);
        }
        sort(times.begin(),times.end());
        for(int i=0;i<times.size();i++){
            int starttime=times[i][0];
            int endtime=times[i][1];
            int findex=times[i][2];
            while(!occupied.empty() && occupied.top().first<=starttime){
                currseat.push(occupied.top().second);
                occupied.pop();
            }
            int chairAssigned = currseat.top();
            currseat.pop();
            if (findex == targetFriend) {
                return chairAssigned;
            }

            // Mark the chair as occupied until the friend's departure time
            occupied.push({endtime, chairAssigned});
        }
                return -1; 


    }   
};
