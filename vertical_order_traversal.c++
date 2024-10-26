class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // BFS Queue and Map Initialization
        queue<TreeNode*> q;
        unordered_map<TreeNode*, int> mp;  // maps node to its horizontal level (hlevel)
        mp[root] = 0;  // root is at hlevel 0
        q.push(root);
        
        // Map to store nodes by (vlevel, hlevel) pairs
        // map<vlevel, map<hlevel, multiset<TreeNode*>>> to keep nodes sorted
        map<int, map<int, multiset<int>>> nodes;

        // Start BFS
        int vlevel = 0;  // Tracks vertical level (depth)
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* a = q.front();
                int hlevel = mp[a];  // get horizontal level of this node
                q.pop();

                // Store node in the map
                nodes[hlevel][vlevel].insert(a->val);

                // Process left child
                if (a->left != NULL) {
                    q.push(a->left);
                    mp[a->left] = hlevel - 1;  // move to the left: horizontal level decreases
                }
                // Process right child
                if (a->right != NULL) {
                    q.push(a->right);
                    mp[a->right] = hlevel + 1;  // move to the right: horizontal level increases
                }
            }
            vlevel++;
        }

        // Prepare the result
        vector<vector<int>> result;
        for (auto& hMap : nodes) {
            vector<int> col;  // column corresponding to current horizontal level
            for (auto& vMap : hMap.second) {
                col.insert(col.end(), vMap.second.begin(), vMap.second.end());
            }
            result.push_back(col);
        }

        return result;
    }
};
