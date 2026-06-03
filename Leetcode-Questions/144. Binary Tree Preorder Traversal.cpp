// Approach 1
// TC = O(N)
// SC = O(N)
class Solution {
    vector<int> ans;
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr)
            return ans;
        ans.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return ans;
    }
};
