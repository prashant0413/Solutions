// Approach 1
// TC = O(N)
// SC = O(H)
class NodeValue {
public:
    int maxValue, minValue, maxSum;
    NodeValue(int x, int y, int z): maxValue(x), minValue(y), maxSum(z) {}
};

class Solution {
    int ans;
public:
    NodeValue largestBST(TreeNode* root) {
        if (!root) return NodeValue(INT_MIN, INT_MAX, 0);

        auto left = largestBST(root->left);
        auto right = largestBST(root->right);

        if (left.maxValue < root->val && root->val < right.minValue) {
            int currSum = left.maxSum + right.maxSum + root->val;
            ans = max(currSum, ans);
            return NodeValue(
                max(root->val, right.maxValue),
                min(root->val, left.minValue),
                currSum
            );
        }
        return NodeValue(INT_MAX, INT_MIN, max(left.maxSum, right.maxSum));
    }

    int maxSumBST(TreeNode* root) {
        ans = 0;
        largestBST(root);
        return ans;
    }
};
