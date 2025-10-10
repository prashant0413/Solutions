/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        // Your code here
        if (head == NULL || head->next == NULL)
            return head;
        
        Node *temp = head;
        while (temp != NULL && temp->next != NULL) {
            Node *nextNode = temp->next;
            if (nextNode != NULL && temp->data == nextNode->data) {
                temp->next = nextNode->next;
                if (nextNode->next)
                nextNode->next->prev = temp;
                delete nextNode;
            }
            else {
                temp = temp->next;
            }
        }
        return head;
    }
};
