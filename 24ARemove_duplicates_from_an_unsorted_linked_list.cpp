// GFG
class Solution
{
    // see code &copy to understand 
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
      if(head->next==NULL) {
          return head;
      }
      map<int,bool>mp;
      Node* prev = NULL;
      Node* curr = head;
      while(curr!=NULL) {
          if(mp[curr->data]== true) {
              prev->next = curr->next;
          }
          else {
              prev = curr;
              mp[curr->data] = true;
          }
          curr = curr->next;
      }
      return head;
    }
};
