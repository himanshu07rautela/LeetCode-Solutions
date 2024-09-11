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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        vector<int>arr;
        
        ListNode*p=head;
        while(p!=NULL){
            int d=p->val;
            arr.push_back(d);
            p=p->next;
        }
        int n=arr.size();
        vector<int>arr2;
        arr2.push_back(arr[0]);
        for(int i=0;i<n-1;i++){
            int a=arr[i];
            int b=arr[i+1];
            int c=gcd(a,b);
            arr2.push_back(c);
            arr2.push_back(b);
        }
        ListNode*ans=new ListNode(-1);
        ListNode*q=ans;
        for(int i=0;i<arr2.size();i++){
            ListNode*r=new ListNode(arr2[i]);
            q->next=r;
            q=r;
        }
        return ans->next;

    }
};