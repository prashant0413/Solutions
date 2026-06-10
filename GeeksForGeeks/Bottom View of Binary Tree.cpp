// Approach 1
// TC = O(N)
// SC = O(N)
class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        if (root == nullptr) return ans;
        queue<pair<Node*, int>> q;
        map<int, int> mpp;
        q.push({root, 0});
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            if (curr.first->left) {
                q.push({curr.first->left, curr.second - 1});
            }
            if (curr.first->right) {
                q.push({curr.first->right, curr.second + 1});
            }
            mpp[curr.second] = curr.first->data;
        }
        for (auto p: mpp) {
            ans.push_back(p.second);
        }
        return ans;
    }
};
