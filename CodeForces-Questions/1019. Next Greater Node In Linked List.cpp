// Approach 1
// TC = O(5n)
// SC = O(3n)

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
    ListNode* reverseLL(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* newHead = reverseLL(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    } 
public:
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* newHead = reverseLL(head);
        stack<int> st;
        ListNode* temp = newHead;
        vector<int> ans;
        while (temp) {
            while (!st.empty() && st.top() <= temp->val)
                st.pop();
            int x = st.empty() ? 0 : st.top();
            ans.push_back(x);
            st.push(temp->val);
            temp = temp->next;
        }
        reverseLL(newHead);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
