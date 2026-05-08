// Approach 1
// TC = O(2N)
// SC = O(N)
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st;
        for (int i: nums) {
            st.insert(i);
        }

        ListNode* p = nullptr;
        ListNode* q = head;
        while (q) {
            if (st.count(q->val)) {
                if (p)
                    p->next = q->next;
                if (q == head) {
                    head = q->next;
                }
                q = q->next;
            } else {
                p = q;
                q = q->next;
            }
        }
        return head;
    }
};
