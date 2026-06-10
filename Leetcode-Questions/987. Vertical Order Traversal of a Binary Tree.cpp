// Approach 1 using level order traversal
// TC = O(N)
// SC = O(N)
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        map<int, map<int, multiset<int>>> mpp;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            TreeNode* curr = p.first;
            int x = p.second.first;
            int y = p.second.second;
            mpp[x][y].insert(curr->val);
            if (curr->left) {
                q.push({curr->left, {x - 1, y + 1}});
            }
            if (curr->right) {
                q.push({curr->right, {x + 1, y + 1}});
            }
        }
        for (auto p: mpp) {
            vector<int> col;
            for (auto q: p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};

// Approach 2 using preorder traversal
// TC = O(N)
// SC = O(N)
class Solution {
    map<int, map<int, multiset<int>>> mpp;
public:
    void helper(TreeNode* root, int x, int y) {
        if (root == nullptr) return;
        mpp[x][y].insert(root->val);
        helper(root->left, x - 1, y + 1);
        helper(root->right, x + 1, y + 1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        helper(root, 0, 0);
        for (auto p: mpp) {
            vector<int> col;
            for (auto q: p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
