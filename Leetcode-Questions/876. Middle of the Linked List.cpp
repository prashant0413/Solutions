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
// Method 1 TC = O(N + N/2) SC = O(1)
// class Solution
// {
//     int getLength(ListNode *head)
//     {
//         ListNode *temp = head;
//         int count = 0;
//         while (temp != nullptr)
//         {
//             count++;
//             temp = temp->next;
//         }
//         return count;
//     }

// public:
//     ListNode *middleNode(ListNode *head)
//     {
//         int length = getLength(head);
//         int mid = length / 2 + 1;
//         ListNode *temp = head;
//         for (int i = 0; i < mid - 1; i++)
//         {
//             temp = temp->next;
//         }
//         return temp;
//     }
// };

// Method 2
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
