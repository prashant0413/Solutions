// Approach 1
// TC = O(N)
// SC = O(N)
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            int size = q.size();
            int mini = q.front().second;
            int first, last;
            for (int i = 0; i < size; i++) {
                int curr = q.front().second - mini;
                TreeNode* node = q.front().first;
                q.pop();
                if (i == 0) first = curr;
                if (i == size - 1) last = curr;
                if (node->left) q.push({node->left, (long long)curr * 2 + 1});
                if (node->right) q.push({node->right, (long long)curr * 2 + 2});
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};
