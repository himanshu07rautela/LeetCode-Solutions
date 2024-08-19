/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* removeKthNode(Node* head, int K)
{
    // Write your code here.
    int n=0;
    Node*p=head;
    while(p!=NULL){
        n++;
        p=p->next;
    }
    int index=n-K;
    if(index==0){
        return head->next;
    }
    p=head;
    Node*q=head;
    Node*r=head;
    for(int i=0;i<index;i++){
        p=p->next;
    }
    for(int i=0;i<index-1;i++){
        q=q->next;
    }
    for(int i=0;i<index+1;i++){
        r=r->next;
    }
    q->next=r;
    delete(p);
    return head;
    
}
