// Approach 1
// TC = O(N^2)
// SC = O(N)
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mpp;
        unordered_map<int, int> parent;
        TreeNode* r = nullptr;
        for (int i = 0; i < descriptions.size(); i++) {
            int root = descriptions[i][0];
            int child = descriptions[i][1];
            int isLeft = descriptions[i][2];

            TreeNode* rNode = nullptr;
            if (mpp.count(root)) {
                rNode = mpp[root];
            } else {
                rNode = new TreeNode(root);
            }

            TreeNode* cNode = nullptr;
            if (mpp.count(child)) {
                cNode = mpp[child];
            } else {
                cNode = new TreeNode(child);
            }

            if (isLeft) rNode->left = cNode;
            else rNode->right = cNode;
            mpp[root] = rNode;
            mpp[child] = cNode;
            parent[child] = root;
            if (r == nullptr)
                r = rNode;
            else if (r == cNode) {
                while (parent.count(r->val)) {
                    r = mpp[parent[r->val]];
                }
            }
        }
        return r;
    }
};

// Approach 2
// TC = O(N)
// SC = O(N)
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mpp;
        unordered_map<int, int> parent;
        for (int i = 0; i < descriptions.size(); i++) {
            int root = descriptions[i][0];
            int child = descriptions[i][1];
            int isLeft = descriptions[i][2];

            TreeNode* rNode = nullptr;
            if (mpp.count(root)) {
                rNode = mpp[root];
            } else {
                rNode = new TreeNode(root);
            }

            TreeNode* cNode = nullptr;
            if (mpp.count(child)) {
                cNode = mpp[child];
            } else {
                cNode = new TreeNode(child);
            }

            if (isLeft) rNode->left = cNode;
            else rNode->right = cNode;
            mpp[child] = cNode;
            mpp[root] = rNode;
            parent[child] = root;
        }

        TreeNode* r = mpp[descriptions[0][0]];
        while (parent.count(r->val)) {
            r = mpp[parent[r->val]];
        }
        return r;
    }
};
