// Approach 1
// TC = O(nlog(n))
// SC = O(1)
class Solution {
public:
    TreeNode* insert(TreeNode* root, int x) {
        if (root == nullptr)
            return new TreeNode(x);
        if (root->val > x) {
            root->left = insert(root->left, x);
        } else {
            root->right = insert(root->right, x);
        }
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = nullptr;
        for (int &i: preorder)
            root = insert(root, i);
        return root;
    }
};

// Approach 2
// TC = O(n)
// SC = O(1)
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& arr) {
        int i = 0;
        return build(arr, i, INT_MAX);
    }

    TreeNode* build(vector<int> &arr, int &i, int bound) {
        if (i == arr.size() || arr[i] > bound) return nullptr;
        TreeNode* root = new TreeNode(arr[i++]);
        root->left = build(arr, i, root->val);
        root->right = build(arr, i, bound);
        return root;
    }
};
