// Approach 1
// TC = O(N)
// SC = O(N)
class Solution {
    int ans;
public:
    int solve(TreeNode* root) {
        if (root == nullptr) return 0;
        int x = solve(root->left);
        int y = solve(root->right);
        if (x < 0) x = 0;
        if (y < 0) y = 0;
        ans = max(ans, x + y + root->val);
        return root->val + max(x, y);
    }

    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        solve(root);
        return ans;
    }
};
