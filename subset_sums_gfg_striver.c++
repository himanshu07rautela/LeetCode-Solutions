class Solution {
  public:
    void solve(vector<int>arr,vector<int>&ans,int sum, int index){
        if(index>=arr.size()){
            ans.push_back(sum);
            return;
        }
        // include
        solve(arr,ans,sum+arr[index],index+1);
        // exclude
        solve(arr,ans,sum,index+1);
        return;
    }
    vector<int> subsetSums(vector<int>arr, int n) {
        // Write Your Code here
        // aah its a classic baktrack 
        vector<int>ans;
        solve(arr,ans,0,0);
        return ans;
    }
};
