// Approach 1
// TC = O(N)
// SC = O(N)
class Solution {
    Node* findNode(Node* root, int target) {
        if (root == nullptr) return nullptr;
        if (root->data == target) return root;
        Node* left = findNode(root->left, target);
        if (left) return left;
        Node* right = findNode(root->right, target);
        if (right) return right;
        return nullptr;
    }
    
    void markParent(Node* root, unordered_map<Node*, Node*> &parent) {
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* curr = q.front(); q.pop();
            if (curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
  public:
    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> parent;
        markParent(root, parent);
        Node* tNode = findNode(root, target);
        queue<Node*> q;
        q.push(tNode);
        int time = 0;
        unordered_map<Node*, bool> visited;
        visited[tNode] = true;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                Node* curr = q.front(); q.pop();
                if (curr->left && !visited[curr->left]) {
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                if (curr->right && !visited[curr->right]) {
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                if (parent[curr] && !visited[parent[curr]]) {
                    q.push(parent[curr]);
                    visited[parent[curr]] = true;
                }
            }
            if (q.size() != 0) time++;
        }
        return time;
    }
};
