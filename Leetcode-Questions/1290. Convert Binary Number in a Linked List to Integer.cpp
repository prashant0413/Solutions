// Approach 1
// TC = O(N)
// SC = O(1)
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        if (head == nullptr)
            return 0;
        int ans = 0;
        ListNode* temp = head;
        while (temp) {
            ans <<= 1;
            ans = ans | (temp->val);
            temp = temp->next;
        }
        return ans;
    }
};
