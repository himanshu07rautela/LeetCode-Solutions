class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        vector<int>a(mat.size(),0);
        vector<int>b(mat.size(),0);
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){
                    b[j]++;// j known to people
                    a[i]++;// people i knows
                }
            }
        }
        for(int i=0;i<mat.size();i++){
            if(a[i]==0 && b[i]==mat.size()-1){
                return i;
            }
        }
        return -1;
    }
};