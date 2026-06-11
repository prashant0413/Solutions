// Approach 1 using iteration
// TC = O(N)
// SC = O(N)
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) { 
        vector<int> ans;
        if (root == nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int x = -1;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front(); q.pop();
                x = temp->val;
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            ans.push_back(x);
        }
        return ans;
    }
};

// Approach 2 using recursion
// TC = O(N)
// SC = O(H)
class Solution {
public:
    void solve(TreeNode* root, int level, vector<int> &ans) {
        if (root == nullptr) return;
        if (level == ans.size())
            ans.push_back(root->val);
        solve(root->right, level + 1, ans);
        solve(root->left, level + 1, ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(root, 0, ans);
        return ans;
    }
};
