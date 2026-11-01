// APPROACH 1: BRUTE FORCE
// TC: O(N)
// SC: O(H)
class Solution {
public:
    bool solve(TreeNode* root, int target, int sum) {
        if (root == nullptr) return false;
        sum += root->val;
        if (!root->left && !root->right) return sum == target;
        if (solve(root->left, target, sum)) return true;
        if (solve(root->right, target, sum)) return true;
        sum -= root->val;
        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        return solve(root, targetSum, 0);
    }
};
