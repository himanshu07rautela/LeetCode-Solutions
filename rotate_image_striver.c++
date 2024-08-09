class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // row1-->column(n-1)
        // row2-->column(n-2)
        // -
        // ...
        // row(n-1)--->column(1)
        // make a duplicate and do the operations
        vector<vector<int>>duplicate(matrix.size(),vector<int>(matrix.size(),0));
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                duplicate[i][j]=matrix[i][j];
            }
        }
        //wha se row uthakar column banana hai 
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[j][n-1-i]=duplicate[i][j];
            }
        }
        return;

        
    }
};