class Solution {
public: 
    void solve(vector<vector<int>>& image, int i, int j, int color1, int color2){
        if(i<0 || i>image.size()-1 || j<0 || j>image[0].size()-1){
            return ;
        }
        if(image[i][j]==color1 ){
            image[i][j]=color2;
            //DFS KA QUESTION HAI BACCHA
            solve(image,i-1,j,color1,color2);
            solve(image,i+1,j,color1,color2);
            solve(image,i,j-1,color1,color2);
            solve(image,i,j+1,color1,color2);
        }else{
            return ;
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         if (image[sr][sc] == color) {
        return image;
    }
        solve(image,sr,sc,image[sr][sc],color);
        return image;

    }
};