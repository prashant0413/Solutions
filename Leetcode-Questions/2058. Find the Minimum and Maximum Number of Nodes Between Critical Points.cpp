// Approach 1
// TC = O(N)
// SC = O(CP)
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return {-1, -1};

        vector<int> cp;
        ListNode* prev = head;
        ListNode* temp = head->next;
        int i = 2;
        while (temp->next) {
            if (prev->val < temp->val && temp->val > temp->next->val) {
                cp.push_back(i);
            } else if (prev->val > temp->val && temp->val < temp->next->val) {
                cp.push_back(i);
            }
            i++;
            prev = temp;
            temp = temp->next;
        }

        int n = cp.size();

        if (n <= 1)
            return {-1, -1};

        int maxi = cp[n - 1] - cp[0];
        int mini = INT_MAX;
        for (i = 1; i < n; i++) {
            mini = min(cp[i] - cp[i - 1], mini);
        }


        return (mini == INT_MAX) ? vector<int>{-1, -1} : vector<int>{mini, maxi};
    }
};
