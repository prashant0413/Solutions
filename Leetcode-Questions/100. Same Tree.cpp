// Approach 1
// TC = O(N)
// SC = O(N)
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;
        queue<TreeNode*> que1, que2;
        que1.push(p);
        que2.push(q);
        while (!que1.empty() && !que2.empty()) {
            int size = que1.size();
            for (int i = 0; i < size; i++) {
                TreeNode* t1 = que1.front(); que1.pop();
                TreeNode* t2 = que2.front(); que2.pop();
                if (t1->left && !t2->left || !t1->left && t2->left) return false;
                if (t1->right && !t2->right || !t1->right && t2->right) return false;
                if (t1->left)
                    que1.push(t1->left);
                if (t1->right)
                    que1.push(t1->right);
                if (t2->left)
                    que2.push(t2->left);
                if (t2->right)
                    que2.push(t2->right);  
                if (t1->val != t2->val)
                    return false;     
            }
        }
        return true;
    }
};
