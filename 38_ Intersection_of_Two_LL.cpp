// 160. Intersection of Two Linked Lists (Leet code)
// https://leetcode.com/problems/intersection-of-two-linked-lists/
// see video to understand


class Solution {
public:
// https://youtu.be/0JHQ26NQcPk
// see video to understand 
int getListLength(ListNode* head) {
    int len = 0;
    while (head != NULL) {
      len++;
      head = head->next;
    }

    return len;
  }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getListLength(headA);
    int lenB = getListLength(headB);
    while(lenA>lenB){
        lenA--;
        headA=headA->next;
    }
    while(lenB>lenA){
        lenB--;
        headB=headB->next;

    }
    while(headA!=headB){
         headA=headA->next;
          headB=headB->next;
    }
    return headA;
    }
};
