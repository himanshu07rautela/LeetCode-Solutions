include<vector>
bool searchMatrix(vector<vector<int>>& mat, int target) {
    // just check if the given number lies between the lowest and the highest in the
    // given row
    for(int i=0;i<mat.size();i++){
        int low=mat[i][0];
        int high=mat[i][mat[i].size()-1];
        if(target>=low && target<=high){
          for (int j = 0; j < mat[i].size(); j++) {
              if(mat[i][j]==target){
                  return true;
              }
          }
        }else{
            continue;
        }
    }
    return false;
}