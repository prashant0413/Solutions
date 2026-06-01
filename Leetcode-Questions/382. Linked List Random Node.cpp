// Approach 1
// TC = O(n)
// SC = O(n)
class Solution {
    vector<int> arr;
    int size;
public:
    Solution(ListNode* head) {
        while (head) {
            arr.push_back(head->val);
            head = head->next;
        }
        size = arr.size();
    }
    
    int getRandom() {
        int idx = rand() % size;
        return arr[idx];
    }
};
