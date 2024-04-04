// 2. Add Two Numbers
// Leetcode

class Solution
{
// https://youtu.be/HiRlTPf9aCg?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA 
// see from starting lec 51 
    private:
     ListNode* reverse( ListNode* head) {
        
         ListNode* curr = head;
         ListNode* prev = NULL;
         ListNode* next = NULL;
        
        while(curr != NULL) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    } 
    
    void insertAtTail(ListNode* &head,ListNode* &tail, int val) {
        
         ListNode* temp = new  ListNode(val);
        //empty list
        if(head == NULL) {
            head = temp;
            tail = temp;
            return;
        }
        else
        {
            tail -> next = temp;
            tail = temp;
        }
    }
    
    ListNode* add(ListNode* first,  ListNode* second) {
        int carry = 0;
        
        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;
        
        while(first != NULL || second != NULL || carry != 0) {
            
            int val1 = 0;
            if(first != NULL)
                val1 = first -> val;
                
            int val2 = 0;
            if(second !=NULL)
                val2 = second -> val;
            
            
            int sum = carry + val1 + val2;
            
            int digit = sum%10;
            
            //create node and add in answer Linked List
            insertAtTail(ansHead, ansTail, digit);
            
            carry = sum/10;
            if(first != NULL)
                first = first -> next;
            
            if(second != NULL)
                second = second -> next;
        }
          
        return ansHead;
    }
    public:
    //Function to add two numbers represented by linked list.
     ListNode* addTwoNumbers( ListNode* first, ListNode* second)
    {
        //step 1 -  reverse input LL
        // first = reverse(first);
        // second = reverse(second);    
        first = (first);
        second = (second);
        //step2 - add 2 LL
        ListNode* ans = add(first, second);
        
        //step 3 
        // ans = reverse(ans);
        ans =ans ;
        
        return ans;
    }
};
