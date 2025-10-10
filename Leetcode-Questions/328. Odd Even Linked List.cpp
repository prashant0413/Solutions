class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *p = head;
        ListNode *q = head->next;
        ListNode *even = q;
        while (q != NULL && q->next != NULL)
        {
            p->next = p->next->next;
            q->next = q->next->next;

            p = p->next;
            q = q->next;
        }
        p->next = even;
        return head;
    }
};
