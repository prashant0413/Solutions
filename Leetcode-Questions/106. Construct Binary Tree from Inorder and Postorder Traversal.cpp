// Approach 1
// TC = O(N)
// SC = O(N)
class Solution {
public:
    TreeNode* buildTree(vector<int>& postorder, int postSt, int postEnd, vector<int>& inorder, int inSt, int inEnd, map<int, int> &inmap) {
        if (postSt > postEnd || inSt > inEnd) return nullptr;

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int rootIdx = inmap[postorder[postEnd]];
        int numsRight = inEnd - rootIdx;
        root->left = buildTree(postorder, postSt, postEnd - numsRight - 1, inorder, inSt, rootIdx - 1, inmap);
        root->right = buildTree(postorder, postEnd - numsRight, postEnd - 1, inorder, rootIdx + 1, inEnd, inmap);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> inmap;
        for (int i = 0; i < inorder.size(); i++) {
            inmap[inorder[i]] = i;
        }

        TreeNode* root = buildTree(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, inmap);
        return root;
    }
};
