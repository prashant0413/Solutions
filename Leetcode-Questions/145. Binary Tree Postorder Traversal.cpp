// Approach 1
// TC = O(N)
// SC = O(N)
class Solution {
public:
    void solve(TreeNode* root, vector<int> &ans) {
        if (root == nullptr) return;
        solve(root->left, ans);
        solve(root->right, ans);
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};

// Approach 2 (Iterative) using 2 stacks
// TC = O(N)
// SC = O(N)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        stack<TreeNode*> st1;
        stack<int> st2;
        st1.push(root);
        while (!st1.empty()) {
            TreeNode* node = st1.top(); st1.pop();
            st2.push(node->val);
            if (node->left)
                st1.push(node->left);
            if (node->right)
                st1.push(node->right);
        }

        while (!st2.empty()) {
            ans.push_back(st2.top()); st2.pop();
        }
        return ans;
    }
};
