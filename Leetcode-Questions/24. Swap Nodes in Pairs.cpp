/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Approach 1
// TC = O(N)
// SC = O(1)
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *p = head;
        ListNode *q = head->next;
        ListNode *t = nullptr;
        while (q) {
            p->next = q->next;
            q->next = p;
            if (p == head)
                head = q;
            if (t)
                t->next = q;
            t = p;
            p = p->next;
            q = p ? p->next : nullptr;
        }
        return head;
    }
};
