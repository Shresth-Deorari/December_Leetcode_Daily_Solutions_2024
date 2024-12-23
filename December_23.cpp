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
private:
    int calc(TreeNode * root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);
            
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                level[i] = node->val;
            }

            vector<pair<int, int>> indexedLevel(size);
            for (int i = 0; i < size; i++) {
                indexedLevel[i] = {level[i], i};
            }
            sort(indexedLevel.begin(), indexedLevel.end());

            vector<bool> visited(size, false);

            for (int i = 0; i < size; i++) {
                if (visited[i] || indexedLevel[i].second == i) {
                    continue; 
                }

                int cycleSize = 0;
                int current = i;

                while (!visited[current]) {
                    visited[current] = true;
                    current = indexedLevel[current].second;
                    cycleSize++;
                }

                if (cycleSize > 1) {
                    ans += cycleSize - 1;
                }
            }
        }
        return ans;
    }

public:
    int minimumOperations(TreeNode* root) {
        return calc(root);
    }
};
