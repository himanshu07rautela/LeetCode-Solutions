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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        
        vector<vector<int>>arr(m,vector<int>(n,-1));
        ListNode*p=head;
        vector<int>v;
        while(p!=NULL){
            int d=p->val;
            v.push_back(d);
            p=p->next;
        }
        int count=0;
        int i=0;
        int k=0;
        while(count < v.size() && i < (m + 1) / 2 && i < (n + 1) / 2){
            for(int j=i;j<n-i;j++){
                arr[i][j]=v[count];
                count++;
                if(count>=v.size()){
                    return arr;
                }
            }
           
            for(int j=i+1 ;j<m-i;j++){
                arr[j][n-1-i]=v[count];
                count++;
                if(count>=v.size()){
                    return arr;
                }
            }
             
              if (i < m - i - 1) {
                for (int j = n - 2 - i; j >= i; j--) {
                    arr[m - 1 - i][j] = v[count++];
                    if (count >= v.size()) return arr;
                }
            }
            
            // Traverse Up
            if (i < n - i - 1) {
                for (int j = m - 2 - i; j > i; j--) {
                    arr[j][i] = v[count++];
                    if (count >= v.size()) return arr;
                }
            }
            
            i++;
        }
        return arr;


    }
};