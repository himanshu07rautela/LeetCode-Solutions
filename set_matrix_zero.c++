class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // we'll make a map<pair<Int,int>,bool> to check if there is zero or not;
        map<pair<int,int>,bool>mp;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    pair<int,int>p=make_pair(i,j);
                    mp[p]=true;
                    continue;
                }
                mp[{i,j}]=false;
            }
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                pair<int,int>p=make_pair(i,j);
                if(mp[p]==true){
                    // change the row and column to zero
                    for(int k=0;k<matrix[i].size();k++){
                        matrix[i][k]=0;
                    }
                    // col
                    for(int k=0;k<matrix.size();k++){
                        matrix[k][j]=0;
                    }
                }
            }
        }
        return ;
    }
};