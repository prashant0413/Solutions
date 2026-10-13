// APPROACH 1: USING SET
// TC: O(N)
// SC: O(N)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> st;
        ListNode* temp = head;
        while (temp) {
            if (st.count(temp)) return temp;
            st.insert(temp);
            temp = temp->next;
        }
        return nullptr;
    }
};

// APPROACH 2: USING SLOW AND FAST POINTER TECHNIQUE
// TC: O(N)
// SC: O(1)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }

        return nullptr;
    }
};
