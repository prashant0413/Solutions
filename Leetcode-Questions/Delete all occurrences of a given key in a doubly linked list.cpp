// User function Template for C++

/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // Write your code here
        Node *temp = *head_ref;
        
        while  (temp != NULL)
        {
            if (temp->data == x)
            {
                Node *del = temp;
                if (temp == *head_ref)
                {
                    *head_ref = temp->next;
                    if (*head_ref != NULL)
                        (*head_ref)->prev = NULL;
                }
                else
                {
                    if (temp->next)
                        temp->next->prev = temp->prev;
                    if (temp->prev)
                        temp->prev->next = temp->next;
                }
                temp = temp->next;
                delete del;
            }
            else
            {
                temp = temp->next;
            }
            
        }
    }
};
