// 138. Copy List with Random Pointer

class Solution {
public:
    Node* copyRandomList(Node* head) {
    map<Node* , Node*> m;
    Node* curr=head;
    Node* nHead=new Node(0);
    
    Node* prev=nHead;
    
    while(curr!=NULL)
    {
        Node* node = new Node(curr->val);
        prev->next=node;
        m.insert({curr,node});
        prev=prev->next;
        curr=curr->next;
    }
    nHead=nHead->next; 

    Node* c1=head;
    Node* c2=nHead;
    
    while(c1!=NULL)
    {
        if(c1->random!=NULL)
            c2->random=m.at(c1->random);
        else
            c2->random =NULL;
        
        c1=c1->next;
        c2=c2->next;
    }
    return nHead;
    }
};