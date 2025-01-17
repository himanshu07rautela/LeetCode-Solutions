//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


vector <int> bottomView(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Heremp;
    
        // levels mapped to Node
        unordered_map<int,int>mp;
        vector<vector<int>>ans;
        queue<pair<Node*,int>>q;
        q.push(make_pair(root,0));
        int s=0;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                pair<Node*,int>a=q.front();
                Node*n=a.first;
                int s=a.second;
                if(mp.find(s)==mp.end()){
                    mp[s]=n->data;
                }else{
                    mp[s]=n->data;
                }
                q.pop();
                if(n->left!=NULL){
                    q.push(make_pair(n->left,s-1));
                }
                if(n->right!=NULL){
                    q.push(make_pair(n->right,s+1));
                }
            }
        }
        for(auto a: mp){
            vector<int>arr(2);
            arr[0]=a.first;
            arr[1]=a.second;
            ans.push_back(arr);
        }
        sort(ans.begin(),ans.end());
        vector<int>ans1;
        for(int i=0;i<ans.size();i++){
            ans1.push_back(ans[i][1]);
        }
        return ans1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.bottomView(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    
cout << "~" << "\n";
}
    return 0;
}



// } Driver Code Ends