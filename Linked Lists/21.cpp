// 21. Merge Two Sorted Lists

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL or l2==NULL) return l1==NULL?l2: l1;
        
        ListNode* c1=l1;
        ListNode* c2=l2;
        ListNode* dummy= new ListNode(0);
        ListNode* temp=dummy;
        
        while(c1!=NULL and c2!=NULL)
        {
            if(c1->val <= c2->val)
            {
                temp->next=c1;
                 c1=c1->next;
                temp=temp->next;
            }
            else
            {
                temp->next=c2;
                c2=c2->next;
                temp=temp->next;
            }
           
        }
        temp->next=c1!=NULL?c1: c2;
        return dummy->next;
    }
};