// Approach 1 (Recursive)
// TC = O(N)
// SC = O(N)
class Solution {
    vector<int> ans;
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr)
            return ans;
        ans.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return ans;
    }
};


// Approach 2 (Iterarive)
// TC = O(N)
// SC = O(N)
class Solution {
public:
    void solve(TreeNode* root, vector<int> &ans) {
        TreeNode* node = root;
        stack<TreeNode*> st;
        while (1) {
            while (node) {
                ans.push_back(node->val);
                st.push(node);
                node = node->left;
            }
            if (st.empty())
                break;
            node = st.top(); st.pop();
            node = node->right;
        }
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};
