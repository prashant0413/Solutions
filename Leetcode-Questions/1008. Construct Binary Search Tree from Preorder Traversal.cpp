// Approach 1
// TC = O(nlog(n))
// SC = O(1)
class Solution {
public:
    TreeNode* insert(TreeNode* root, int x) {
        if (root == nullptr)
            return new TreeNode(x);
        if (root->val > x) {
            root->left = insert(root->left, x);
        } else {
            root->right = insert(root->right, x);
        }
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = nullptr;
        for (int &i: preorder)
            root = insert(root, i);
        return root;
    }
};
