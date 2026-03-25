// Approach 1
// TC = O(N)
// SC = O(1)
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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head)
            return nullptr;
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while (temp) {
            if (temp->val == val) {
                ListNode* del = temp;
                if (del == head) {
                    head = head->next;
                }
                temp = temp->next;
                if (prev)
                    prev->next = temp;
                delete del;   
            } else {
                prev = temp;
                temp = temp->next;
            }
        } 
        return head;  
    }
};
