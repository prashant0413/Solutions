// Approach 1 using queue
// TC = O(N)
// SC = O(N)
class Solution {
public:
    void preorder(TreeNode* root, queue<TreeNode*> &q) {
        if (root == nullptr) return;

        q.push(root);
        preorder(root->left, q);
        preorder(root->right, q);
    }

    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        queue<TreeNode*> q;
        preorder(root, q);
        TreeNode* temp = q.front();
        q.pop();
        while (!q.empty()) {
            temp->right = q.front();
            temp->left = nullptr;
            q.pop();
            temp = temp->right;
        }
    }
};

// Approach 2
// TC = O(N)
// SC = O(N)
class Solution {
    TreeNode* prev;
public:
    void solve(TreeNode* root) {
        if (root == nullptr)
            return;

        solve(root->right);
        solve(root->left);

        root->right = prev;
        root->left = nullptr;
        prev = root;
    }

    void flatten(TreeNode* root) {
        prev = nullptr;
        solve(root);
    }
};

// Approach 3 using stack
// TC = O(N)
// SC = O(N)
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* curr = st.top(); st.pop();
            if (curr->right)
                st.push(curr->right);
            if (curr->left)
                st.push(curr->left);
            if (!st.empty())
                curr->right = st.top();
            curr->left = nullptr;
        }
    }
};
