// Approach 1
// TC = O(N)
// SC = O(N)
class BSTIterator {
    vector<int> inorder;
    int i;
public:
    BSTIterator(TreeNode* root) {
        i = 0;
        while (root) {
            if (root->left == nullptr) {
                inorder.push_back(root->val);
                root = root->right;
            } else {
                TreeNode* prev = root->left;
                while (prev->right && prev->right != root) {
                    prev = prev->right;
                }
                if (prev->right == nullptr) {
                    prev->right = root;
                    root = root->left;
                } else {
                    prev->right = nullptr;
                    inorder.push_back(root->val);
                    root = root->right;
                }
            }
        }
    }
    
    int next() {
        return inorder[i++];
    }
    
    bool hasNext() {
        return i < inorder.size();
    }
};
