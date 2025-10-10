class Solution
{
    int findLength(Node *slow, Node *fast)
    {
        int count = 1;
        fast = fast->next;
        while (slow != fast)
        {
            count++;
            fast = fast->next;
        }
        return count;
    }

public:
    int lengthOfLoop(Node *head)
    {
        Node *slow = head;
        Node *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return findLength(slow, fast);
        }
        return 0;
    }
};
