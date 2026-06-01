// Approach 1
class Solution {
    vector<int> arr;
    int size;
public:
    Solution(ListNode* head) {
        while (head) {
            arr.push_back(head->val);
            head = head->next;
        }
        size = arr.size();
    }
    
    int getRandom() {
        int idx = rand() % size;
        return arr[idx];
    }
};

// Approach 2
class Solution {
    ListNode* Head;
public:
    Solution(ListNode* head) {
        Head = head;
    }
    
    int getRandom() {
        int cnt = 1;
        int result = 0;

        ListNode* temp = Head;
        while (temp) {
            if (rand() % cnt < 1.0 / cnt) {
                result = temp->val;
            }
            temp = temp->next;
            cnt++;
        }
        return result;
    }
};
