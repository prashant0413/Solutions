// Approach 1
// TC = O(N*N)
// SC = O(1)
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        if (head == nullptr)
            return head;
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while (temp) {
            int sum = 0;
            ListNode* curr = temp;
            while (curr) {
                sum += curr->val;
                if (sum == 0) {
                    if (prev)
                        prev->next = curr->next;
                    else
                        head = curr->next;
                    break;
                } else {
                    curr = curr->next;
                }
            }
            if (sum == 0)
                temp = curr->next;
            else {
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};
