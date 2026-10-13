// APPROACH 1: RECURSIVE
// TC: O(N)
// SC: O(N)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};

// APPROACH 2: ITERATIVELY
// TC: O(N)
// SC: O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* temp = head;
        ListNode* prev = nullptr;
        while (temp) {
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }

        return prev;
    }
};
