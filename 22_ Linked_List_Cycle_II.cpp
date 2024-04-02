// 142. Linked List Cycle II
// Leetcode
// Find starting node of  Cycle loop 
// Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
// https://leetcode.com/problems/linked-list-cycle-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // https://youtu.be/VxOFflTXlXo?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA
class Solution {
public:
ListNode *floydDetectLoop(ListNode *head)
{
     if (head == NULL)
        return NULL;

        ListNode *slow = head;
        ListNode *fast = head;

    while (slow != NULL && fast != NULL)
    {

        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }

        slow = slow->next;

        if (slow == fast)
        {
    
            return slow;
        }
    }

    return NULL;
    }

   
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL)
        return NULL;

        ListNode *intersection = floydDetectLoop(head);

    if (intersection == NULL)
        return NULL;

        ListNode *slow = head;

    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}
};
