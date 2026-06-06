// Approach 1
// TC = O(N)
// SC = O(N)
class Solution {
    int ans;
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int x = maxDepth(root->left);
        int y = maxDepth(root->right);
        ans = max(x + y, ans);
        return max(x,y) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        maxDepth(root);
        return ans;
    }
};
