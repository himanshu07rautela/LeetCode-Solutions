class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Create adjacency list
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);

        for (const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]); // Directed edge: pre[1] -> pre[0]
            inDegree[pre[0]]++;
        }

        // Use a queue to perform BFS
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) { // Start with courses having no prerequisites
                q.push(i);
            }
        }

        int visited = 0;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            visited++;

            for (int next : adj[course]) {
                inDegree[next]--;
                if (inDegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        // If we visited all courses, there's no cycle
        return visited == numCourses;
    }
};
