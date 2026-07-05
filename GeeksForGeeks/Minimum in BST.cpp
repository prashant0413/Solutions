// Approach 1
// TC = O(log(N))
// SC = O(1)
class Solution {
  public:
    int minValue(Node* root) {
        if (root == nullptr) return -1;
        while (root->left) {
            root = root->left;
        }
        return root->data;
    }
};
