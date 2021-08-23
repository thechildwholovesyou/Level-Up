/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL or head->next==NULL) return head;
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next=NULL;
        
        while(curr!=NULL)
        {
            // store the next pointer next
            next=curr->next;
            // reverse curr node pointer 
            curr->next=prev;
            // move pointers 
            prev=curr;
            curr=next;
        }
        head=prev;
        return head;
    }
};