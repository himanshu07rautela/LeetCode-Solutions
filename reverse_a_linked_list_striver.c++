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
        // there are 2 ways of doing it
        // one is using a vector and much more easy and other is using logic
        // and reverse it without taking any extra space
        // 1 method
        // vector<int>a;
        // ListNode*p=head;
        // while(p!=NULL){
        //     int d=p->val;
        //     a.push_back(d);
        //     p=p->next;
        // }
        // reverse(a.begin(),a.end());
        // ListNode*ans=new ListNode(-1);
        // ListNode*q=ans;
        // for(int i=0;i<a.size();i++){
        //     int d=a[i];
        //     ListNode*p=new ListNode(d);
        //     q->next=p;
        //     q=p;
        // }
        // return ans->next;
        // 2nd method 
        ListNode*p=head;
        ListNode*q=NULL;
        while(p!=NULL){
            ListNode*r=p->next;
            p->next=q;
            q=p;
            p=r;
        }
        return q;
        
    }
};