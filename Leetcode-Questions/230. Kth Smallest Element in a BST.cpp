// Approach 1 using morris traversal
// TC = O(N)
// SC = O(1)
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* curr = root;
        int ans = 0;
        while (curr) {
            if (curr->left == nullptr) {
                k--;
                if (k == 0)
                    ans = curr->val;
                curr = curr->right;
            } else {
                TreeNode* last = curr->left;
                while (last->right && last->right != curr) {
                    last = last->right;
                }

                if (last->right == nullptr) {
                    last->right = curr;
                    curr = curr->left;
                } else {
                    last->right = nullptr;
                    k--;
                    if (k == 0)
                        ans = curr->val;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};
