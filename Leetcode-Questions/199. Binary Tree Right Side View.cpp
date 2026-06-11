// Approach 1
// TC = O(N)
// SC = O(N)
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int x = -1;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front(); q.pop();
                x = temp->val;
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            ans.push_back(x);
        }
        return ans;
    }
};
