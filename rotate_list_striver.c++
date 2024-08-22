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
    ListNode* rotateRight(ListNode* head, int k) {
        // first lets make this linked list circular
        if(head==NULL || head->next==NULL || k==0){
            return head;
        }
        ListNode*last=head;
        ListNode*start=head;
        int n=0;
        while(last->next!=NULL){
            n++;
            last=last->next;
        }
        last->next=start;
        // in case k >n , we handle using this case
        k=k%(n+1);
        int times=(n+1)-k;
        ListNode*p=start;
        for(int i=0;i<times-1;i++){
            p=p->next;
        }
        // p will be pointing towards the lastnode , and q is the head node real one
        // but in order to delete the last node and start node's connection we need
        // lastnode to point null and return q(start node)
        ListNode*q=p->next;
        p->next=NULL;
        return q;
    }
};