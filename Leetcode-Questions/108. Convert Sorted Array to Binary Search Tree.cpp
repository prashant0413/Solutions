// Approach 1
// TC = O(N)
// SC = O(N)
class Solution {
public:
    TreeNode* build(int low, int high, vector<int> &nums) {
        if (low > high) return nullptr;
        int mid = low + (high - low) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = build(low, mid - 1, nums);
        root->right = build(mid + 1, high, nums);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(0, nums.size() - 1, nums);
    }
};
