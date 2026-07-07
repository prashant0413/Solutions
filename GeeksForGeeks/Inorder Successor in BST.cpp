// Approach 1
// TC = O(N)
// SC = O(N)
class Solution {
  public:
    int inOrderSuccessor(Node *root, Node *k) {
        vector<int> inorder;
        Node* curr = root;
        while (curr) {
            if (curr->left == nullptr) {
                inorder.push_back(curr->data);
                curr = curr->right;
            } else {
                Node* prev = curr->left;
                while (prev->right && prev->right != curr) {
                    prev = prev->right;
                }
                if (prev->right == nullptr) {
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    prev->right = nullptr;
                    inorder.push_back(curr->data);
                    curr = curr->right;
                }
            }
        }
        
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == k->data) {
                return i + 1 < inorder.size() ? inorder[i + 1] : -1;
            }
        }
        return -1;
    }
}

// Approach 2
// TC = O(N)
// SC = O(1)
class Solution {
  public:
    int inOrderSuccessor(Node *root, Node *k) {
        int ans = -1;
        Node* curr = root;
        while (curr) {
            if (curr->left == nullptr) {
                if (curr->data > k->data && ans == -1)
                    ans = curr->data;
                curr = curr->right;
            } else {
                Node* prev = curr->left;
                while (prev->right && prev->right != curr) {
                    prev = prev->right;
                }
                if (prev->right == nullptr) {
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    prev->right = nullptr;
                    if (curr->data > k->data && ans == -1)
                        ans = curr->data;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};

// Approach 3
// TC = O(H)
// SC = O(1)
class Solution {
  public:
    int inOrderSuccessor(Node *root, Node *k) {
        Node* successor = NULL;
        Node* curr = root;
        while (curr) {
            if (curr->data <= k->data) {
                curr = curr->right;
            } else {
                successor = curr;
                curr = curr->left;
            }
        }
        return successor ? successor->data : -1;
    }
};
