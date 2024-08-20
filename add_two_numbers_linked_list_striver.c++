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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*ans= new ListNode(-1);
        ListNode*p=ans;
        int carry=0;
        while(l1!=NULL && l2!=NULL){
            int data=l1->val +l2->val + carry;
            carry=data/10;
            int curr=data%10;
            ListNode*q=new ListNode(curr);
            p->next=q;
            p=q;
            l1=l1->next;
            l2=l2->next;
        }
        if(l1!=NULL){
            while(l1!=NULL){
                 int data=l1->val + carry;
                 carry=data/10;
                 int curr=data%10;
                 ListNode*q=new ListNode(curr);
                 p->next=q;
                 p=q;
                 l1=l1->next;
            }

        }
        if(l2!=NULL){
            while(l2!=NULL){
                 int data=l2->val + carry;
                 carry=data/10;
                 int curr=data%10;
                 ListNode*q=new ListNode(curr);
                 p->next=q;
                 p=q;
                 l2=l2->next;
            }

        }
        if(carry!=0){
            ListNode*q=new ListNode(carry);
            p->next=q;
            p=q;
        }
        return ans->next;
    }
};