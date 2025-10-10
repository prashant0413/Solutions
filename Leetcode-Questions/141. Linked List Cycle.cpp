/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return false;
        ListNode *slow = head;
        ListNode *fast = head;
        do
        {
            slow = slow->next;
            if (fast->next != nullptr)
            fast = fast->next->next;
            if (slow == fast)
                return true;
        } while (fast != nullptr && fast->next != nullptr);
        return false;
    }
};
