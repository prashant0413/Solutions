// APPROACH 1: USING TREE TRAVERSAL
// TC: O(N)
// SC: O(H)
class Solution {
    int ans;
public:
    void solve(TreeNode* root, int num) {
        if (root == nullptr) return;
        num = num * 10 + root->val;
        if (!root->left && !root->right)  {
            ans += num;
            return;
        }
        solve(root->left, num);
        solve(root->right, num);
    }

    int sumNumbers(TreeNode* root) {
        ans = 0;
        solve(root, 0);
        return ans;
    }
};
