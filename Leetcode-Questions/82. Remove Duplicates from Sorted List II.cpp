// Approach 1
// TC = O(N)
// SC = o(1)

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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* tail = nullptr;
        ListNode* temp = head;
        while (temp && temp->next) {
            if (temp->val != temp->next->val) {
                tail = temp;
                temp = temp->next;
            } else {
                ListNode* p = temp->next;
                while (p && p->val == temp->val) {
                    p = p->next;
                }
                if (temp == head) {
                    head = p;
                } else {
                    tail->next = p;
                }
                temp = p;
            }
        }
        return head;
    }
};
