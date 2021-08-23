// 141. Linked List Cycle

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL or head->next==NULL) return false;
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(slow!=NULL and fast!=NULL and fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast) return true;
        }
        return false; 
    }
};
