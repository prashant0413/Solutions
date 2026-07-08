// Approach 1
// TC = O(3N)
// SC = O(N)
class Solution {
public:
    vector<int> inorder(TreeNode* root) {
        vector<int> res;
        while (root) {
            if (root->left == nullptr) {
                res.push_back(root->val);
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
                    res.push_back(root->val);
                    root = root->right;
                }
            }
        }
        return res;
    }

    void updateTree(TreeNode* root, vector<int> &arr) {
        int i = 0;
        TreeNode* curr = root;
        while (curr) {
            if (curr->left == nullptr) {
                curr->val = arr[i++];
                curr = curr->right;
            } else {
                TreeNode* prev = curr->left;
                while (prev->right && prev->right != curr) {
                    prev = prev->right;
                }
                if (prev->right == nullptr) {
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    prev->right = nullptr;
                    curr->val = arr[i++];
                    curr = curr->right;
                }
            }
        }
    }

    void recoverTree(TreeNode* root) {
        if (root == nullptr) return;
        vector<int> arr = inorder(root);
        int st = -1;
        int en = -1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i - 1] > arr[i]) {
                if (st == -1) st = i - 1;
                en = i;
            }
        }
        swap(arr[st], arr[en]);
        updateTree(root, arr);
    }
};

// Approach 1
// TC = O(N)
// SC = O(1)
class Solution {
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    TreeNode* prev;
public:
    void inorder(TreeNode* root) {
        if (root == nullptr) return;
        inorder(root->left);
        if (prev != nullptr && prev->val > root->val) {
            if (first == nullptr) {
                first = prev;
                middle = root;
            } else {
                last = root;
            }
        }
        prev = root;
        inorder(root->right);
    }


    void recoverTree(TreeNode* root) {
        first = middle = last = nullptr;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if (first && last) swap(first->val, last->val);
        else if (first && middle) swap(first->val, middle->val);
    }
};
