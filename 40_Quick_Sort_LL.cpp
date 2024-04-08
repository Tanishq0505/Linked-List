// Quick Sort on Linked List 
// gfg

// https://www.youtube.com/watch?v=q0crmlC7VdM
// see video to understand 
node* getTail(node* head){
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    return temp;
}
node* partition(node* head,node* tail){
    node* pivot=head;
    node* prev =head;
    node* curr=head->next;
    while(curr!=tail->next){
        if(pivot->data>curr->data){
            swap(prev->next->data,curr->data);
            prev=prev->next;
        }
        curr=curr->next;
    }
    swap(pivot->data,prev->data);
    return prev;
}
void solve(node* head,node* tail){
    if(head==NULL||tail==NULL||head==tail)
    return;
    node* pivot=partition(head,tail);
    solve(head,pivot);
    solve(pivot->next,tail);
}
void quickSort(struct node **headRef) {
    node *head=*headRef;
    if(head==NULL||head->next==NULL){
        return;
    }
    node *tail=getTail(head);
    solve(head,tail);
}
