#include <queue>
#include <utility>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;  // Handle edge case for empty tree

        queue<pair<TreeNode*, long long>> q;  // Use long long to avoid overflow
        q.push({root, 0});
        int ans = 0;  // Initialize answer to 0

        while (!q.empty()) {
            int n = q.size();
            long long start = q.front().second;  // Start index of the level
            long long end = start;  // Initialize end with start

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front().first;
                end = q.front().second;  // Update end index
                q.pop();

                // Push left child with its index
                if (node->left) {
                    q.push({node->left, 2 * (end - start) + 1});  // Relative index
                }

                // Push right child with its index
                if (node->right) {
                    q.push({node->right, 2 * (end - start) + 2});  // Relative index
                }
            }
            ans = max(ans, static_cast<int>(end - start + 1));  // Calculate width
        }
        return ans;
    }
};
