// 142. Linked List Cycle II

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL or head->next==NULL) return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        
        bool isCycle=false;
        
        while(fast!=NULL and fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                isCycle=true;
                break;
            }
        }
        slow=head;
        if(!isCycle) return NULL;
        
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};