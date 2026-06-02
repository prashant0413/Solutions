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

// Approach 2
// TC = O(N*N)
// SC = O(N)
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        if (head == nullptr)
            return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        unordered_map<int, ListNode*> mpp;
        mpp[0] = dummy;
        int preSum = 0;
        while (head) {
            preSum += head->val;
            if (mpp.count(preSum)) {
                ListNode* start = mpp[preSum];
                ListNode* temp = start;
                int pre = preSum;
                while (temp != head) {
                    temp = temp->next;
                    pre += temp->val;
                    if (temp != head)
                        mpp.erase(pre);
                }
                start->next = head->next;
            } else {
                mpp[preSum] = head;
            }
            head = head->next;
        }
        return dummy->next;
    }
};
