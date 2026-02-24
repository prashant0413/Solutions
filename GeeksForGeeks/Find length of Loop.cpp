// Approach 1
// TC = O(N)
// SC = O(N)
class Solution {
  public:
    int lengthOfLoop(Node *head) {
        unordered_map<Node*, int> mpp;
        Node *temp = head;
        int cnt = 0;
        while (temp != NULL) {
            if (mpp.count(temp)) {
                return cnt + 1 - mpp[temp];
            }
            cnt++;
            mpp[temp] = cnt;
            temp = temp->next;
        }
        return 0;
    }
};

// Approach 2
// TC = O(2N)
// SC = O(1)
class Solution {
  public:
    int findLength(Node *slow, Node *fast) {
        int cnt = 1;
        fast = fast->next;
        while (slow != fast) {
            cnt++;
            fast = fast->next;
        }
        return cnt;
    }
  
    int lengthOfLoop(Node *head) {
        Node *slow = head;
        Node *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return findLength(slow, fast);
        }
        return 0;
    }
};
