// Approach 1
// TC = O(N)
// SC = O(N)
class Solution {
public:
    vector<int> inorder(TreeNode* root) {
        vector<int> res;
        while (root) {
            if (root->left == nullptr) {
                res.push_back(root->val);
                root = root->right;
            } else {
                TreeNode* prev = root->left;
                while (prev->right && prev->right != root) {
                    prev = prev->right;
                }
                if (prev->right == nullptr) {
                    prev->right = root;
                    root = root->left;
                } else {
                    prev->right = nullptr;
                    res.push_back(root->val);
                    root = root->right;
                }
            }
        }
        return res;
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> arr = inorder(root);
        int l, r;
        l = 0;
        r = arr.size() - 1;
        while (l < r) {
            if (arr[l] + arr[r] == k)
                return true;
            if (arr[l] + arr[r] > k)
                r--;
            else
                l++;
        }
        return false;
    }
};
