// Approach 1 (Recursive)
// TC = O(N)
// SC = O(N)
class Solution {
public:
    void solve(TreeNode* root, vector<int> &ans) {
        if (root == nullptr)
            return;
        
        solve(root->left, ans);
        ans.push_back(root->val);
        solve(root->right, ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};

// Approach 2 (Iterative)
// TC = O(N)
// SC = O(N)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* node = root;
        stack<TreeNode*> st;
        while (1) {
            while (node) {
                st.push(node);
                node = node->left;
            }

            if (st.empty()) break;
            node = st.top(); st.pop();
            ans.push_back(node->val);
            node = node->right;
        }
        return ans;
    }
};
