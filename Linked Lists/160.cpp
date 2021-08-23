// 160. Intersection of Two Linked Lists

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL or headB==NULL) return NULL;
        
        ListNode* c1=headA;
        ListNode* c2=headB;
        
        while(c1!=c2)
        {
            c1=c1->next;
            c2=c2->next;
            
            if(c1==c2) return c1;
            
            if(c1==NULL) c1=headB;
            
            if(c2==NULL) c2=headA;
        }
        return c1;
    }
};