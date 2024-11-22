//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void solve(vector<vector<int>>&adj, unordered_map<int,bool>&mp,vector<int>&ans,int index){
        if(index>=adj.size()){
            return;
        }
        ans.push_back(index);
        mp[index]=true;
        for(auto a: adj[index]){
            if(mp[a]!=true){
                solve(adj,mp,ans,a);
            }
        }
        return;
    }
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        // Code here
        //here we have to dfs of a graph, go recursion
        // adjacency list is given 
        unordered_map<int,bool>mp;
        vector<int>ans;
        solve(adj,mp,ans,0);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends