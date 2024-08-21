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
    bool isPalindrome(ListNode* head) {
        // its palindrome question and it can be done easily
        // compare the reversed one with the real one, O(N) , we can avoid it using runner's algo
        // reach middle and then reverse the linked list and 

        // ListNode*p=head;
        // vector<int>arr;
        // while(p!=NULL){
        //     arr.push_back(p->val);
        //     p=p->next;
        // }
        // for(int i=0;i<arr.size()/2;i++){
        //     if(arr[i]!=arr[arr.size()-1-i]){
        //         return false;
        //     }
        // }
        // return true;
        // first is to find which one it is 
        int n=0;
        ListNode*p=head;
        while(p!=NULL){
            n++;
            p=p->next;
        }
        if(n==1){
            return true;
        }
        if(n==2){
            return head->val == head->next->val;
        }
        ListNode*slow=head;
        ListNode*fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*prev=NULL;
        ListNode*curr=slow->next;
        // lets revrse it man
        while(curr!=NULL){
            ListNode*n=curr->next;
            curr->next=prev;
            prev=curr;
            curr=n;
        }
        ListNode*s=head;
        ListNode*e=prev;
       
        while(e!=NULL){
            if(s->val!=e->val){
                return false;
            }
            s=s->next;
            e=e->next;
            
        }
        return true;

    }
};