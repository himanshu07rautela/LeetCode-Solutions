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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // we'll not use vector this time otherwise we're fucked
        // unordered_map should be used
        unordered_map<ListNode*,bool>mp;
        ListNode*p=headA;
        ListNode*q=headB;
        while(p!=NULL){
            mp[p]=true;
            p=p->next;
        }
        while(q!=NULL){
            if(mp.find(q)!=mp.end() && mp[q]==true){
                return q;
            }
            mp[q]=true;
            q=q->next;

        }
       
        return q;


        
    }
};