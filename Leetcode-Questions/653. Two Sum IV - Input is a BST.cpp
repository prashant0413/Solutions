// Approach 1
// TC = O(N)
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

    bool findTarget(TreeNode* root, int k) {
        vector<int> arr = inorder(root);
        int l, r;
        l = 0;
        r = arr.size() - 1;
        while (l < r) {
            if (arr[l] + arr[r] == k)
                return true;
            if (arr[l] + arr[r] > k)
                r--;
            else
                l++;
        }
        return false;
    }
};

// Approach 1
// TC = O(N)
// SC = O(1)
class BSTIterator {
    stack<TreeNode*> st;
    bool isBefore;
public:
    BSTIterator(TreeNode* root, bool before) {
        isBefore = before;
        addAll(root);
    }

    int next() {
        TreeNode* curr = st.top();
        st.pop();
        if (!isBefore) addAll(curr->right);
        else addAll(curr->left);
        return curr->val;
    }

private:
    void addAll(TreeNode* root) {
        while (root) {
            st.push(root);
            if (isBefore) {
                root = root->right;
            } else {
                root = root->left;
            }
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        BSTIterator low(root, false);
        BSTIterator high(root, true);
        int i = low.next();
        int j = high.next();
        while (i < j) {
            if (i + j == k) return true;
            if (i + j < k) i = low.next();
            else j = high.next();
        }
        return false;
    }
};
