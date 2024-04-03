// 876 Leetcode 
// Middle of the Linked List
// https://leetcode.com/problems/middle-of-the-linked-list/submissions/981863854/

class Solution {
    // https://youtu.be/vqS1nVQdCJM?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA
    // see approach 1 from 36 min 
public:
    int length(ListNode* head){
        int len = 0;
        while(head != NULL)
        {
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode* middleNode(ListNode* head) {
        int len = length(head);
        int ans = len/2;

        ListNode* temp = head;
        int cnt = 0;
        while(cnt < ans)
        {
            temp = temp->next;
            cnt++;
        }
        return temp;
    }
};
