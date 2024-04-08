// Sort a k sorted doubly linked list (GFG)


class Solution
{
    // see code and do dry run to undesratnd 
public:
    // function to sort a k sorted doubly linked list
    DLLNode *sortAKSortedDLL(DLLNode *head, int k)
    {
// This part of the code is a check to handle the case when "k" is zero.In such a case,
// it means that the list is already sorted, so the function returns the head of the list as
// it is.
         if(k==0)
        {
            return head;
        }
// Here, the code traverses the doubly linked list and stores the data of each node in a 
// vector arr. Then, it sorts the vector arr using the std::sort function. This essentially
// sorts all the elements of the doubly linked list.        
        vector<int> arr;
        DLLNode* temp=head;
        while(temp!=NULL)
        {
            arr.push_back(temp->data);
            temp=temp->next;
        }
        sort(arr.begin(),arr.end());
        // After sorting the vector arr, the code traverses the doubly linked list again.
        // It updates the data of each node with the sorted values from the vector arr.
        temp=head;
        int i=0;
        while(temp!=NULL)
        {
            temp->data=arr[i];
            temp=temp->next;
            i++;
        }
        // Finally, the function returns the head of the doubly linked list, which is now sorted.

        return head;
    }
};
