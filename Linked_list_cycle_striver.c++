/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // the runner's algorithm  is used for the  finding of middle of linked list and this floyd detection algo whihc is 
        // used for the finding of cycle in linked list
        if(head==NULL || head->next==NULL){
            return false;
        }
        ListNode*p=head;
        ListNode*q=head;
        // jo aage hai usko 2 -2 badhauynga and jo peeche hai usko 1 ek badaunga;
        // its optimised beacuse it doesn't take any extra space 
        // otherwise we can make it using maps
        while(p!=NULL and q!=NULL){
            
            if(p->next!=NULL){
                p=p->next;
            }else{
                break;
            }
            if(q->next!=NULL){
                q=q->next;
                if(q->next!=NULL){
                    q=q->next;
                    if(p==q){
                       return true;
                     }
                }else{
                    break;
                }
            }else{
                break;
            }
        }
        return false;

        
    }
};