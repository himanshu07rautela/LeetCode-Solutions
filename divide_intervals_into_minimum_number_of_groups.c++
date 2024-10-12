class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        priority_queue<int,vector<int>,greater<int>>pq;
        sort(intervals.begin(),intervals.end());
        
        for(int i=0;i<intervals.size();i++){
            int etime=intervals[i][1];
            int stime=intervals[i][0];
            if(!pq.empty() && pq.top()<stime){
                pq.pop();
            }
            pq.push(etime);
        }
        return pq.size();
    }
};