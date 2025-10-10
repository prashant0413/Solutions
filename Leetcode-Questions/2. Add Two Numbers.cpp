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
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *head1, ListNode *head2)
    {
        ListNode *dummyNode = new ListNode(-1);
        ListNode *t1 = head1;
        ListNode *t2 = head2;
        ListNode *curr = dummyNode;
        int carry = 0;
        while (t1 != NULL || t2 != NULL)
        {
            int sum = carry;
            if (t1 != NULL)
                sum += t1->val;
            if (t2 != NULL)
                sum += t2->val;
            curr->next = new ListNode(sum % 10);
            carry = sum / 10;
            if (t1 != NULL)
                t1 = t1->next;
            if (t2 != NULL)
                t2= t2->next;
            curr = curr->next;
        }
        if (carry)
        {
            curr->next = new ListNode(carry);
        }
        return dummyNode->next;
    }
};
