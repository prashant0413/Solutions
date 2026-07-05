// Approach 1
// TC = O(log(N))
// SC = O(1)
class Solution {
public:
    TreeNode* solve(TreeNode* root, int x) {
        if (root == nullptr) return nullptr;
        if (root->val == x) return root;
        if (x > root->val) return solve(root->right, x);
        return solve(root->left, x);
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        return solve(root, val);
    }
};
