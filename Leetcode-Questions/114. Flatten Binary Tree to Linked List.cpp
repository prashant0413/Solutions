// Approach 1 using queue
// TC = O(N)
// SC = O(N)
class Solution {
public:
    void preorder(TreeNode* root, queue<TreeNode*> &q) {
        if (root == nullptr) return;

        q.push(root);
        preorder(root->left, q);
        preorder(root->right, q);
    }

    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        queue<TreeNode*> q;
        preorder(root, q);
        TreeNode* temp = q.front();
        q.pop();
        while (!q.empty()) {
            temp->right = q.front();
            temp->left = nullptr;
            q.pop();
            temp = temp->right;
        }
    }
};
