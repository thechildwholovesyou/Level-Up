// 1290. Convert Binary Number in a Linked List to Integer

class Solution {
public:
    int length(ListNode* head)
    {
        if(head==NULL) return 0;
        int cnt=0;
        ListNode* curr=head;
        
        while(curr!=NULL)
        {
            cnt++;
            curr=curr->next;
        }
        return cnt;
    }
    
    int getDecimalValue(ListNode* head) {
        if(head==NULL) return 0;
        if(head->next==NULL) return head->val;
        
        int l=length(head);
        int num=0;
        ListNode* curr=head;
        
        while(curr!=NULL)
        {
            int temp=curr->val;
            num+=temp*pow(2,l-1);
            l--;
            curr=curr->next;
        }
        return num;
    }
};