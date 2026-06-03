// Approach 1
// TC = O(2N)
// SC = O(N)
class Solution {
public:
    int totalNodes(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int n = 1;
        n += totalNodes(root->left);
        n += totalNodes(root->right);
        return n;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        int n = totalNodes(root);
        vector<vector<int>> ans(n);
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            pair<TreeNode*, int> p = q.front();
            q.pop();
            if (p.first->left) {
                q.push({p.first->left, p.second + 1});
            }
            if (p.first->right) {
                q.push({p.first->right, p.second + 1});
            }

            ans[p.second].push_back(p.first->val);
        }

        for (int i = n - 1; i >= 0; i--) {
            if (ans[i].size() == 0)
                ans.pop_back();
        }

        return ans;
    }
};

// Approach 2
// TC = O(N)
// SC = O(N)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                TreeNode* t = q.front();
                q.pop();
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
                level.push_back(t->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};
