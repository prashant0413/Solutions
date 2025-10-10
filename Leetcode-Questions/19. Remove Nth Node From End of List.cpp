// class Solution
// {
// public:
//     ListNode *removeNthFromEnd(ListNode *head, int n)
//     {
//         int len = 0;
//         ListNode *temp = head;
//         while (temp != NULL)
//         {
//             len++;
//             temp = temp->next;
//         }
//         if (len == n)
//         {
//             ListNode *del = head;
//             head = head->next;
//             delete (del);
//             return head;
//         }
//         int index = len - n;
//         ListNode *p = NULL;
//         ListNode *q = head;
//         for (int i = 0; i < index; i++)
//         {
//             p = q;
//             q = q->next;
//         }
//         p->next = q->next;
//         delete (q);
//         return head;
//     }
// };

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        for (int i = 0; i < n; i++)
            fast = fast->next;
        if (fast == NULL)
        {
            ListNode *del = head->next;
            head = head->next;
            delete (del);
            return head;
        }
        while (fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *del = slow->next;
        slow->next = slow->next->next;
        delete (del);
        return head;
    }
};
