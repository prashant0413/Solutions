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
// TC =  O(M) + O(MLOG(M)) + O(M) WHERE M = N * K : N = no. of elements and K : no. of lists
// SC = O(M) + O(M)
class Solution {
    ListNode *convert(vector<int> &arr) {
        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;
        for (int i = 0; i < arr.size(); i++) {
            temp->next = new ListNode(arr[i]);
            temp = temp->next;
        }
        return dummy->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> arr;
        for (int i = 0; i < lists.size(); i++) {
            ListNode *temp = lists[i];
            while (temp != nullptr) {
                arr.push_back(temp->val);
                temp = temp->next;
            }
        }
        sort(arr.begin(), arr.end());
        ListNode *head = convert(arr);
        return head;
    }
};


// APPROACH 2
// TC = O(N * K * (K + 1) / 2)
// SC = O(1)
class Solution {
    ListNode *mergeList(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;
        ListNode *t1 = l1, *t2 = l2;
        while (t1 && t2) {
            if (t1->val < t2->val) {
                temp->next = t1;
                temp = t1;
                t1 = t1->next;
            } else {
                temp->next = t2;
                temp = t2;
                t2 = t2->next;   
            }
        }
        if (t1)
            temp->next = t1;
        if (t2)
            temp->next = t2;
        return dummy->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return nullptr;
        ListNode *head = lists[0];
        for (int i = 1; i < lists.size(); i++) {
            head = mergeList(head, lists[i]);
        }
        return head;
    }
};


// APPROACH 3
// TC = O(N LOG(K))
// SC = O(K)
class Compare{
public:
    bool operator()(ListNode *l1, ListNode *l2) {
        return l1->val > l2->val;
    }
 };
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;

        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr)
                pq.push(lists[i]);
        }

        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;

        while (!pq.empty()) {
            ListNode *smallest = pq.top();
            pq.pop();

            temp->next = smallest;
            temp = smallest;

            if (smallest->next != nullptr)
                pq.push(smallest->next);
        }

        return dummy->next;
    }
};
