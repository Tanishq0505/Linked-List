// 23. Merge k Sorted Lists(Leet code)
// https://www.youtube.com/watch?v=1zktEppsdig
// see video to understand

class Solution {
public:
// https://www.youtube.com/watch?v=1zktEppsdig
// see video to understand
    ListNode* mergeKLists(vector<ListNode*>& lists) {

    priority_queue<pair<int,ListNode*>,
    vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
    for(int i=0;i<lists.size();i++){
        if(lists[i]){
            pq.push({lists[i]->val,lists[i]});
        }
    }
    ListNode* dummy=new ListNode(-1);
ListNode* temp=dummy;
while(!pq.empty()){
    auto it=pq.top();
    pq.pop();
    if(it.second->next)
    pq.push({it.second->next->val,it.second->next});
    temp->next=it.second;
    temp=temp->next;
    }

    return dummy->next;
    }
};
