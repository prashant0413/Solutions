// Approach 1
// TC = O(N)
// SC = O(N)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            vector<int> temp;
            for (int i = 0; i < size; i++) {
                TreeNode* t = q.front(); q.pop();
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
                temp.push_back(t->val);
            }
            if (level & 1)
                reverse(begin(temp), end(temp));
            ans.push_back(temp);
            level += 1;
        }
        return ans;
    }
};
