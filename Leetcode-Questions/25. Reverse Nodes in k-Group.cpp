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
    ListNode *reverseList(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *temp = head;
        ListNode *prev = NULL;
        while (temp != NULL) {
            ListNode *nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
        }
        return prev;
    }
    ListNode *findNode(ListNode* head, int k) {
        ListNode *temp = head;
        while (temp != NULL && k > 1) {
            temp = temp->next;
            k--;
        }
        return temp;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *temp = head;
        ListNode *prevNode = NULL;
        ListNode *nextNode = NULL;
        while (temp != NULL) {
            ListNode *kthNode = findNode(temp, k);
            if (kthNode == NULL) {
                if (prevNode) {
                    prevNode->next = temp;
                    break;
                }
            }
            nextNode = kthNode->next;
            kthNode->next = NULL;
            reverseList(temp);
            if (temp == head) {
                head = kthNode;
            } else {
                prevNode->next = kthNode;
            }
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};
