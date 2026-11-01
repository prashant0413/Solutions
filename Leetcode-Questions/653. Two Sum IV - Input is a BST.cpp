// APPROACH 1: NAIVE
// TC: O(N)
// SC: O(N)
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

// APPROACH 2: USING BST_ITERATOR
// TC: O(N)
// SC: O(1)
class BST_Iterator {
private:
    stack<TreeNode*> st;
    bool isBack;
public:
    BST_Iterator(TreeNode* root, bool isBack) {
        this->isBack = isBack;
        addAll(root);
    }

    int next() {
        TreeNode* temp = st.top(); st.pop();
        (isBack) ? addAll(temp->left) : addAll(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }

private:
    void addAll(TreeNode* root) {
        while (root) {
            st.push(root);
            root = isBack ? root->right : root->left;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        BST_Iterator l(root, 0);
        BST_Iterator r(root, 1);

        int i = l.next();
        int j = r.next();
        while (i < j) {
            if (i + j == k) return true;
            if (i + j > k) j = r.next();
            else i = l.next();
        }
        
        return false;
    }
};
