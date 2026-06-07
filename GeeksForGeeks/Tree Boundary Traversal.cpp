// Approach 1
// TC = O(N)
// SC = O(N)
class Solution {
    vector<int> ans;
  public:
    // checking node leaf node or not
    bool isLeaf(Node *node) {
        if (node)
            return !node->left && !node->right;
        return false;
    }
    
    // adding left boundary excludes leaves
    void addLeftBoundary(Node *root) {
        Node* curr = root->left;
        while (curr) {
            if (!isLeaf(curr)) ans.push_back(curr->data);
            if (curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }
    
    // adding leaf nodes
    void addLeafNodes(Node *root) {
        if (isLeaf(root)) {
            ans.push_back(root->data);
            return;
        }
        if (root->left) addLeafNodes(root->left);
        if (root->right) addLeafNodes(root->right);
    }
    
    // adding right boundary
    void addRightBoundary(Node *root) {
        Node* curr = root->right;
        stack<int> st;
        while (curr) {
            if (!isLeaf(curr)) st.push(curr->data);
            if (curr->right) curr = curr->right;
            else curr = curr->left;
        }
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
    }
  
    vector<int> boundaryTraversal(Node *root) {
        if (root == nullptr) return ans;
        if (!isLeaf(root)) ans.push_back(root->data);
        addLeftBoundary(root);
        addLeafNodes(root);
        addRightBoundary(root);
        return ans;
    }
};
