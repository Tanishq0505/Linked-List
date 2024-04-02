// 206 Leetcode
// Given the head of a singly linked list, reverse the list, and return the reversed list.

class Solution {
public:
    // https://youtu.be/vqS1nVQdCJM?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA
    // approach 1 from lec 45
    ListNode* reverseList(ListNode* head) {

if(head==NULL||head->next==NULL){
    return head;
}
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            
        }
        return prev;
    }
};
