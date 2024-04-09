// )61. Rotate List (Leet code)
// // https://youtu.be/8TTH7A-txZI
// // see video and do dry run to understand

class Solution {
public:
// https://youtu.be/8TTH7A-txZI
// see video and do dry run to understand 
    
         ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr)
            return nullptr;

        ListNode* curr = head;
        int size = 1;

        // calculating length and making a circular loop
        while (curr->next != nullptr) {
            curr = curr->next;
            ++size;
        }

        curr->next = head;

        // cut from the rotating point
        int i = size - (k % size);

        while (i > 1) {
            head = head->next;
            i--;
        }

        curr = head->next;
        head->next = nullptr;
        return curr;
    }
};
