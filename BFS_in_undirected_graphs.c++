//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        // Code here
        // dfs had some form of recusrsion in it , and bfs had some form of 
        // queue in it , in binary trees
        unordered_map<int,bool>mp;
        queue<int>q;
        int index=0;
        mp[index]=true;
        q.push(index);
        
        vector<int>ans;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                int num=q.front();
                ans.push_back(num);
                
                q.pop();
                for(auto a: adj[num]){
                    if(mp[a]!=true){
                        mp[a]=true;
                        q.push(a);
                    }
                }
            }
        }
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

        // Now using vector of vectors instead of array of vectors
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); // For undirected graph, add both u->v and v->u
        }

        Solution obj;
        vector<int> ans = obj.bfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends