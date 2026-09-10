// Approach 1
// TC = O(N)
// SC = O(N)
class Solution {
    int cnt;
public:
    pair<int, int> solve(TreeNode* root) {
        if (root == nullptr) return {0, 0};
        pair<int, int> l = solve(root->left);
        pair<int, int> r = solve(root->right);
        int sum = root->val + l.first + r.first;
        int n = 1 + l.second + r.second;
        if (sum / n == root->val) cnt++;
        return {sum, n};
    }

    int averageOfSubtree(TreeNode* root) {
        cnt = 0;
        solve(root);
        return cnt;
    }
};
