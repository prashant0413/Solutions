// Approach 1
// TC = O(n)
// SC = O(n)
class Solution {
    ListNode* reverseLL(ListNode* node) {
        if (node == nullptr || node->next == nullptr)
            return node;
        ListNode* newHead = reverseLL(node->next);
        node->next->next = node;
        node->next = nullptr;
        return newHead;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* f1 = reverseLL(l1);
        ListNode* f2 = reverseLL(l2);
        int carry = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        ListNode* t1 = f1;
        ListNode* t2 = f2;
        while (t1 || t2 || carry) {
            int sum = carry;
            if (t1) {
                sum += t1->val;
                t1 = t1->next;
            }

            if (t2) {
                sum += t2->val;
                t2 = t2->next;
            }
            
            temp->next = new ListNode(sum % 10);
            temp = temp->next;
            carry = sum / 10;
        }
        reverseLL(f1);
        reverseLL(f2);
        return reverseLL(dummy->next);
    }
};
