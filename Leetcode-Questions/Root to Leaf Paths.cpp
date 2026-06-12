// Approach 1
// TC = O(N)
// SC = O(N)
class Solution {
  public:
  
    bool isLeaf(Node* node) {
        return node->left == nullptr && node->right == nullptr;
    }
  
    void solve(Node* root, vector<int> &temp, vector<vector<int>> &ans) {
        if (root == nullptr) return;
        temp.push_back(root->data);
        if (isLeaf(root)) {
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        solve(root->left, temp, ans);
        solve(root->right, temp, ans);
        temp.pop_back();
    }
  
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        vector<int> temp;
        if (root == nullptr) return ans;
        solve(root, temp, ans);
        return ans;
    }
};
