// Approach 1
// TC = O(N)
// SC = O(N)
class Solution {
  public:
    bool isLeaf(Node *node) {
        return node->left == nullptr && node->right == nullptr;
    }
  
    bool isSumProperty(Node *root) {
        if (root == nullptr || isLeaf(root)) return true;
        int sum = root->left ? root->left->data : 0;
        sum += root->right ? root->right->data : 0;
        return (sum == root->data) && isSumProperty(root->left) && isSumProperty(root->right);
    }
};
