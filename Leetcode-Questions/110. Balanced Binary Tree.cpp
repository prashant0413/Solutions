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

// Approach 2
// TC = O(N)
// SC = O(N)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int x = maxDepth(root->left);
        if (x == -1) return -1;
        int y = maxDepth(root->right);
        if (y == -1) return -1;
        if (abs(x - y) > 1) return -1;
        return 1 + max(x, y);
    }

    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            true;
        return maxDepth(root) != -1;
    }
};
