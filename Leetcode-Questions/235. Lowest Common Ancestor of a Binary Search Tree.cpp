// Approach 1
// TC = O(LOG(N))
// SC = O(LOG(N))
class Solution {
public:
    void findPath(TreeNode* root, TreeNode* target, vector<TreeNode*> &arr) {
        if (root == nullptr) return;
        if (root->val == target->val) {
            arr.push_back(root);
            return;
        }
        if (root->val > target->val) {
            arr.push_back(root);
            findPath(root->left, target, arr);
        } else {
            arr.push_back(root);
            findPath(root->right, target, arr);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> toP;
        findPath(root, p, toP);    
        vector<TreeNode*> toQ;
        findPath(root, q, toQ);    

        int n = min(toP.size(), toQ.size());
        TreeNode* mini = root;
        for (int i = 0; i < n; i++) {
            if (toP[i] == toQ[i])
                mini = toP[i];
        }
        return mini;
    }
};
