class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>>ans(rowSum.size(),vector<int>(colSum.size(),0));
        int i,j;
        for( i=0, j=0;i<rowSum.size() && j<colSum.size() ;i+=(rowSum[i]==0),j+=(colSum[j]==0)){
            int added=min(rowSum[i],colSum[j]);
            rowSum[i]-=added;
            colSum[j]-=added;
            ans[i][j]=added;
        }
        return ans;
    }
};