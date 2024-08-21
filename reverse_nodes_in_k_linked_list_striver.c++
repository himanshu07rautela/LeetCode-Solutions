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
    // reverse function bana lo, fir ek while loop me laga do
    ListNode* reverseKGroup(ListNode* head, int k) {
        // we'll try with vector first, and its works just by returing the head 
        // because it has only values changed not the interconections
        // it can also be done without vectors and it will have O(1) space complexity
        vector<int>arr;
        ListNode*p=head;
        while(p!=NULL){
            arr.push_back(p->val);
            p=p->next;
        }
        p=head;
        for(int i=0;i<arr.size();i+=k){
            vector<int>curr(k);
            if(i+k<=arr.size()){
                for(int j=i;j<i+k;j++){
                    curr[j-i]=arr[j];
                }
                reverse(curr.begin(),curr.end());
                for(int j=i;j<i+k;j++){
                    p->val=curr[j-i];
                    p=p->next;
                }
            }else{
                for(int j=i;j<arr.size();j++){
                    p->val=arr[j];
                    p=p->next;
                }

            }
        }
        return head;
        
        
    }
};