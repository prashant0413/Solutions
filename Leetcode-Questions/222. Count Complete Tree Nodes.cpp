// Approach 1
// TC = O(N)
// SC = O(N)
class Solution {
public:
    int solve(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return 1 + solve(root->left) + solve(root->right);
    }

    int countNodes(TreeNode* root) {
        return solve(root);
    }
};


// Approach 2
// TC = O((log(n)^2)
// SC = O(log(n))
class Solution {
public:
    int findLeftHeight(TreeNode* node) {
        TreeNode* curr = node;
        int h = 0;
        while (curr) {
            curr = curr->left;
            h++;
        }
        return h;
    }

    int findRightHeight(TreeNode* node) {
        TreeNode* curr = node;
        int h = 0;
        while (curr) {
            curr = curr->right;
            h++;
        }
        return h;
    }


    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;

        int lh = findLeftHeight(root);   
        int rh = findRightHeight(root);

        if (lh == rh) return (1 << lh) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);   
    }
};
