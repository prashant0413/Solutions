/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
    Node *mergeList(Node *l1, Node *l2) {
        Node *t1 = l1;
        Node *t2 = l2;
        Node *dummy = new Node(-1);
        Node *temp = dummy;
        while (t1 != NULL && t2 != NULL) {
            if (t1->data < t2->data) {
                temp->bottom = t1;
                temp = t1;
                t1 = t1->bottom;
            } else {
                temp->bottom = t2;
                temp = t2;
                t2 = t2->bottom;
            }
            temp->next = NULL;
        }
        if (t1)
            temp->bottom = t1;
        if (t2)
            temp->bottom = t2;
        if (dummy->bottom)
            dummy->bottom->next = NULL;
        return dummy->bottom;
    }
  public:
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *head) {
        // Your code here
        if (head == NULL || head->next == NULL)
            return head;
        
        Node *mergeHead = flatten(head->next);
        return mergeList(head, mergeHead);
    }
};
