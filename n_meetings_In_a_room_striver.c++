//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        // Your code here
        // we just need to check if start of the new meeting > end of last meeting 
        int ans=0;
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back(make_pair(end[i],start[i]));
        }
        sort(v.begin(),v.end());
        int e=0;
        for(int i=0;i<n;i++){
            if(v[i].second>e){
                ans++;
                e=v[i].first;
            }
        }
        return ans;
        
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends