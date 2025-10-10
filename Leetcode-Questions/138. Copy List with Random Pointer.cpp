/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // 1. creating Nodes
        Node *temp = head;
        while (temp != NULL) {
            Node *newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }

        // 2. connecting randome pointer
        temp = head;
        while(temp != NULL) {
            Node *copyNode = temp->next;
            if (temp->random) {
                copyNode->random = temp->random->next;
            } else {
                copyNode->random = NULL;
            }
            temp = temp->next->next;
        }

        // 3. connecting next pointer
        Node *dummy = new Node(-1);
        Node *curr = dummy;
        temp = head;
        while (temp != NULL) {
            curr->next = temp->next;
            temp->next = curr->next->next;
            temp = temp->next;
            curr = curr->next;
        }
        return dummy->next;
    }
};
