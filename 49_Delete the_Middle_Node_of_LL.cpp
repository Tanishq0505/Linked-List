// 2095. Delete the Middle Node of a Linked List (Leet code)
// /see code and do dry run to understand

class Solution {
public:
// /see code and do dry run to understand
    ListNode* deleteMiddle(ListNode* head) {
     if(head == NULL){
            return head;
        }
        if(head->next == NULL){
            return NULL;
        }
    

    ListNode *slow = head;
    ListNode *fast = head->next;
     int count = 0;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
        slow = slow->next;
           count ++;
    }
  ListNode* temp = head;
        int counter = 0;
        while(temp != NULL){
            if(counter == count-1){
                break;
            }
            temp = temp->next;
            counter++;
        }

        temp->next = slow->next;
        slow->next = NULL;
        delete slow;

        return head;
    }
};
