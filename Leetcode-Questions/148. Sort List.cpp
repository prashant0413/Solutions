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
    ListNode *findMiddle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode *mergeList(ListNode *left, ListNode *right)
    {
        ListNode *dummyNode = new ListNode(-1);
        ListNode *temp = dummyNode;
        ListNode *t1 = left;
        ListNode *t2 = right;
        while (t1 != NULL && t2 != NULL)
        {
            if (t1->val < t2->val)
            {
                temp->next = t1;
                t1 = t1->next;
                temp = temp->next;
            }
            else
            {
                temp->next = t2;
                t2 = t2->next;
                temp = temp->next;
            }
        }
        if (t1)
            temp->next = t1;
        else
            temp->next = t2;
        return dummyNode->next;
    }

public:
    ListNode *sortList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *middle = findMiddle(head);
        ListNode *leftHead = head;
        ListNode *rightHead = middle->next;
        middle->next = nullptr;
        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);
        return mergeList(leftHead, rightHead);
    }
};
