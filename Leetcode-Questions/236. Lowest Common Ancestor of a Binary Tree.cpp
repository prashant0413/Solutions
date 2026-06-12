// Approach 1
// TC = O(N)
// SC = O(2N)
class Solution {
public:
    bool pathToNode(TreeNode* p,  int val, vector<TreeNode*> &ds) {
        if (p == nullptr) return false;

        ds.push_back(p);
        if (p->val == val) return true;
        if (pathToNode(p->left, val, ds) || pathToNode(p->right, val, ds)) {
            return true;
        }
        ds.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> arr1;
        vector<TreeNode*> arr2;
        pathToNode(root, p->val, arr1);
        pathToNode(root, q->val, arr2);
        TreeNode* common = root;
        int n1 = arr1.size();
        int n2 = arr2.size();
        int i, j;
        i = j = 0;
        while (i < n1 && j < n2) {
            if (arr1[i] == arr2[j]) {
                common = arr1[i];
                i++;
                j++;
            } else {
                break;
            }
        }
        return common;
    }
};
