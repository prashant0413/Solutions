/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node *zeroHead = new Node(-1);
        Node *oneHead = new Node(-1);
        Node *twoHead = new Node(-1);
        
        Node *zero = zeroHead;
        Node *one = oneHead;
        Node *two = twoHead;
        Node *temp = head;
        
        while (temp != NULL)
        {
            if (temp->data == 0)
            {
                zero->next = temp;
                zero = temp;
            }
            else if (temp->data == 1)
            {
                one->next = temp;
                one = temp;
            }
            else
            {
                two->next = temp;
                two = temp;
            }
            temp = temp->next;
        }
        
        zero->next = (oneHead->next != NULL) ? oneHead->next : twoHead->next;
        one->next = twoHead->next;
        two->next = NULL;
        
        head = zeroHead->next;
        delete(zeroHead);
        delete(oneHead);
        delete(twoHead);
        return head;
    }
};
