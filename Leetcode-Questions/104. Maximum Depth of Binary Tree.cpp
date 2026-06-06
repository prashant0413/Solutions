// Approach 1 (Recursive)
// TC = O(N)
// SC = O(N)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int n = 1;
        int x = maxDepth(root->left);
        int y = maxDepth(root->right);
        return n + max(x, y);
    }
};
