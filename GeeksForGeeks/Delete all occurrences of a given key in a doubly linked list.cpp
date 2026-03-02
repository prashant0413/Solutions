// Approach 1
// TC = O(N)
// SC = O(1)
/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        Node *temp = *head_ref;
        while (temp) {
            Node *del = NULL;
            if (temp->data == x) {
                if (temp == *head_ref) {
                    *head_ref = temp->next;
                }
                Node *nextNode = temp->next;
                Node *prevNode = temp->prev;
                if (nextNode) nextNode->prev = prevNode;
                if (prevNode) prevNode->next = nextNode;
                del = temp;
            }
            temp = temp->next;
            if (del) delete del;
        }
    }
};
