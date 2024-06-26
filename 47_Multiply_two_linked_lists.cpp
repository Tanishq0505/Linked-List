// Multiply two linked lists (GFG)
// https://www.geeksforgeeks.org/problems/multiply-two-linked-lists/1

long long  multiplyTwoLists (Node* l1, Node* l2)
{
    // https://youtu.be/OgjqIUdNlmQ
    // see video to understand
  //Your code here
   long mod = 1000000007;
          long n1 = 0;
          long n2 = 0;
           while(l1 !=NULL) {
              n1 = ((n1*10) + l1->data) % mod;
              l1 = l1->next;
          }
          while(l2 != NULL) {
              n2 = ((n2*10) + l2->data) % mod;
              l2 = l2->next;
          }
          return (n1 * n2) % mod;
}
