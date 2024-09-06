//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
     // Helper function to count elements <= mid in each row
    int countSmallerThanOrEqualToMid(const vector<int>& row, int mid) {
        // Since rows are sorted, use binary search
        return upper_bound(row.begin(), row.end(), mid) - row.begin();
    }

    int median(vector<vector<int>> &matrix, int R, int C){
        // code here
        // i have a very strange idea which is collect every
        int s=1;
        int e=2000;
        int needed=(R * C + 1) / 2;
        while(s<e){
            int mid=s+(e-s)/2;
            int count=0;
            for(int i=0;i<R;i++){
                count += countSmallerThanOrEqualToMid(matrix[i], mid);
            }
            if(count<needed){
                s=mid+1;
            }else{
                e=mid;
            }
        }
         return s;
    }
   
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends