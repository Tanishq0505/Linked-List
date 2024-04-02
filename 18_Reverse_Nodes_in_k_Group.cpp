// 25 Leet code 
// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
// Question link
// https://leetcode.com/problems/reverse-nodes-in-k-group/description/


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
//  https://youtu.be/fi2vh0nQLi0?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA
// see from starting 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
// base case
     if (head == NULL){
            return head;
     }
    //  step 0 is not explain in lecture
         //step0-we check that if k group is avaliable or not to reverse 
       ListNode* cursor = head;
        for(int i = 0; i < k; i++){
            if(cursor == nullptr) {
                //return head if  k group is not present to reverse
            return head;
            }
            cursor = cursor->next;
        }
// step 1 reverse first k nodes
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        int count=0;

        while(curr != NULL && count < k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        // step 2 recursion dekh lega aga 
        if(next != NULL){
            head->next = reverseKGroup(next,k);
        }
        // step 3 return head of reverse list
        return prev;
    }
};
