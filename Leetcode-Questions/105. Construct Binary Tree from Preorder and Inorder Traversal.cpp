// Approach 1
// TC = O(N)
// SC O(N)
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, int preSt, int preEnd, vector<int>& inorder, int inSt, int inEnd,  unordered_map<int, int> &inMap) {
        if (preSt > preEnd || inSt > inEnd) return nullptr;

        TreeNode* root = new TreeNode(preorder[preSt]);
        int rootIdx = inMap[preorder[preSt]];
        int nums = rootIdx - inSt;
        root->left = buildTree(preorder, preSt + 1, preSt + nums, inorder, inSt, rootIdx - 1, inMap);
        root->right = buildTree(preorder, preSt + 1 + nums, preEnd, inorder, rootIdx + 1, inEnd, inMap);
        return root;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        TreeNode* root = buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
        return root;
    }
};
