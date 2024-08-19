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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // it has 2 ways of doing it 
        // similar as last time using vector and not using vector
        // vector<int>arr;
        // ListNode*p=list1;
        // ListNode*q=list2;
        // while(p!=NULL){
        //     int d=p->val;
        //     arr.push_back(d);
        //     p=p->next;
        // }
        // while(q!=NULL){
        //     int d=q->val;
        //     arr.push_back(d);
        //     q=q->next;
        // }
        // sort(arr.begin(),arr.end());
        // ListNode*ans=new ListNode(-1);
        // p=ans;
        // for(int i=0;i<arr.size();i++){
        //     ListNode*q=new ListNode(arr[i]);
        //     p->next=q;
        //     p=q;
        // }
        // return ans->next;
        // 2nd method
        ListNode*p=list1;
        ListNode*q=list2;
        ListNode*ans=new ListNode(-1);
        ListNode*r=ans;
        while(p!=NULL && q!=NULL){
            int d1=p->val;
            int d2=q->val;
            if(d1<=d2){
                ListNode*s=new ListNode(d1);
                r->next=s;
                r=s;
                p=p->next;
            }else{
                ListNode*s=new ListNode(d2);
                r->next=s;
                r=s;
                q=q->next;

            }
        }
        if(p!=NULL){
            while(p!=NULL){
                 int d1=p->val;
                ListNode*s=new ListNode(d1);
                r->next=s;
                r=s;
                p=p->next;

            }
        }
        if(q!=NULL){
            while(q!=NULL){
                 int d1=q->val;
                ListNode*s=new ListNode(d1);
                r->next=s;
                r=s;
                q=q->next;

            }
        }
        return ans->next;

        
    }
};