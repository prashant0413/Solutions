// Approach 1
// TC = O(N)
// SC = O(N)
class Solution {
public:
    void getParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = q.front(); q.pop();
            if (curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        getParents(root,  parent);
        unordered_map<TreeNode*, bool> visited;
        visited[target] = true;
        queue<TreeNode*> q;
        q.push(target);
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            if (level == k) break;
            level++;
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front(); q.pop();
                if (curr->left && !visited[curr->left]) {
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                if (curr->right && !visited[curr->right]) {
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                if (parent[curr] && !visited[parent[curr]]) {
                    q.push(parent[curr]);
                    visited[parent[curr]] = true;
                }
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};
