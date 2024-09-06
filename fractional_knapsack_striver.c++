//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Your code here
        vector<pair<double,double>>density;
        for(int i=0;i<n;i++){
            double a=(double)(arr[i].value)/(arr[i].weight);
            double b=arr[i].weight;
          
            density.push_back({a,b});
        }
          sort(density.begin(), density.end(), [](const pair<double, double> &a, const pair<double, double> &b) {
            return a.first > b.first;
        });
        int i=0;
        double w1=w;
        double ans=0;
        while(w1!=0 && i<n){
            if(density[i].second<w1){
                w1=w1-density[i].second;
                ans=ans+(density[i].first*density[i].second);
                i++;
            }else{
                
                ans=ans+(w1*density[i].first);
                w1=0;
              
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--) {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends