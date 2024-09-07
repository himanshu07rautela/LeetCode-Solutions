//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        // code here
        int i=0;
        int j=0;
        int n=arr1.size();
        int m=arr2.size();
        int count=0;
        int ans=0;
        for(count=0;count<k;count++){
            if(i<n && j<m){
                if(arr1[i]<arr2[j]){
                    ans=arr1[i];
                    i++;
                }else{
                    ans=arr2[j];
                    j++;
                }
            }else if(i<n){
                ans=arr1[i];
                i++;
                
            }else{
                ans=arr2[j];
                j++;
            }
        }
        return ans;
        
    }
};


//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends