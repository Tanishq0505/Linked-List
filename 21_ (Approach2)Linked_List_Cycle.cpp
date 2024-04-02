// 141. Linked List Cycle
// https://leetcode.com/problems/linked-list-cycle/description/

Given head, the head of a linked list, determine if the linked list has a cycle in it.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
// https://youtu.be/VxOFflTXlXo?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA
// To understand see Lec47  Approach 2 floyd  cycle detection
    bool hasCycle(ListNode *head) {
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
};
