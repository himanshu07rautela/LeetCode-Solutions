/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // so the plan was in my head even when i was sleeping
        Node*p=head;
        Node*ans=new Node(-1);
        Node*q=ans;
        unordered_map<Node*,Node*>mp;
        while(p!=NULL){
            Node*n=new Node(p->val);
            mp[p]=n;
            q->next=n;
            q=n;
            p=p->next;
        }
    // mapping is done and now we need to just make random mapping according to the mapped elements
    q=ans->next;
    p=head;
    while(p!=NULL){
        if(p->random==NULL){
            q->random=NULL;
        }else{
            q->random=mp[p->random];
        }
        p=p->next;
        q=q->next;
    }
    return ans->next;
    }

        
    
};