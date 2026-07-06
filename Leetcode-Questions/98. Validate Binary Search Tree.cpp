// Approach 1
// TC = O(n^2)
// SC = O(n)
class Solution {
public:
    int findMin(TreeNode* root) {
        if (root == nullptr) return INT_MAX;
        TreeNode* curr = root;
        int mini = INT_MAX;
        while (curr) {
            if (curr->left == nullptr) {
                mini = min(curr->val, mini);
                curr = curr->right;
            } else {
                TreeNode* prev = curr->left;
                while (prev->right && prev->right != curr) {
                    prev = prev->right;
                }

                if (prev->right == nullptr) {
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    prev->right = nullptr;
                    mini = min(mini, curr->val);
                    curr = curr->right;
                }
            }
        }
        return mini;
    }

    int findMax(TreeNode* root) {
        if (root == nullptr) return INT_MIN;
        TreeNode* curr = root;
        int maxi = INT_MIN;
        while (curr) {
            if (curr->left == nullptr) {
                maxi = max(curr->val, maxi);
                curr = curr->right;
            } else {
                TreeNode* prev = curr->left;
                while (prev->right && prev->right != curr) {
                    prev = prev->right;
                }

                if (prev->right == nullptr) {
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    prev->right = nullptr;
                    maxi = max(maxi, curr->val);
                    curr = curr->right;
                }
            }
        }
        return maxi;
    }

    bool isBST(TreeNode* root) {
        if (root == nullptr) return true;
        if (isBST(root->left) == false) return false;
        if (isBST(root->right) == false) return false;
        long long leftValue = root->left == nullptr ? (long long)root->val - 1 : findMax(root->left);
        long long rightValue = root->right == nullptr ? (long long)root->val + 1 : findMin(root->right);
        return leftValue < root->val && root->val < rightValue;
    }

    bool isValidBST(TreeNode* root) {
        return isBST(root);
    }
};
