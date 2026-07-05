// Approach 1
// TC = O(log(N))
// SC = O(1)
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;

        if (root->val == key) {
            return helper(root);
        }
        TreeNode* temp = root;
        while (root) {
            if (root->val > key) {
                if (root->left && root->left->val == key) {
                    root->left = helper(root->left);
                    break;
                } else {
                    root = root->left;
                }
            } else {
                if (root->right && root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                } else  {
                    root = root->right;
                }
            }
        }
        return temp;
    }

    TreeNode* helper(TreeNode* root) {
        if (root->left == nullptr)
            return root->right;
        if (root->right == nullptr)
            return root->left;

        TreeNode* rightChild = root->right;
        TreeNode* lastFromLeft = findLast(root->left);
        lastFromLeft->right = rightChild;
        return root->left;
    }

    TreeNode* findLast(TreeNode* root) {
        if (root->right == nullptr)
            return root;
        return findLast(root->right);
    }
};
