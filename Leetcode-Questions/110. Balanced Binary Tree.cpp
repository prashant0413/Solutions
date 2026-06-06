// Approach 1
// TC = O(N^2)
// SC = O(N)
class Solution {
public:
    int height(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int n = 1;
        int x = maxDepth(root->left);
        int y = maxDepth(root->right);
        return n + max(x, y);
    }

    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;
        int l, r;
        if (!isBalanced(root->left) || !isBalanced(root->right)) return false;
        l = maxDepth(root->left);
        r = maxDepth(root->right);
        return abs(l - r) < 2;
    }
};
