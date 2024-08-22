class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    void solve(Node*p,vector<int>&ans){
        while(p!=NULL){
          int d=p->data;
          ans.push_back(d);
          p=p->bottom;
        }
    }
    Node *flatten(Node *root) {
        // Your code here
        // we can actually do it very brute forcely
        // find the number of total linked lists
        int n=0;
        Node*p=root;
        while(p!=NULL){
            n++;
            p=p->next;
        }
        // now what we'll do is we'll try getting all the elemenets one list by another
        p=root;
        vector<int>ans;
        while(p!=NULL){
            solve(p,ans);
            p=p->next;
        }
        sort(ans.begin(),ans.end());
        Node*q=new Node(-1);
        Node*r=q;
        for(int i=0;i<ans.size();i++){
            Node*n=new Node(ans[i]);
            r->bottom=n;
            r=n;
        }
        return q->bottom;
        
        
    }
};
