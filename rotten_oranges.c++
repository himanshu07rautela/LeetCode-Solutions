class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        // we can make a ds with 4 directions and kind of like make a graph 
        // with 4 directions and connect them first and then we will traverse it 
        // find out how much time it takes
        vector<pair<int,int>>dir{{1,0},{-1,0},{0,1},{0,-1}};
        queue<pair<int,int>>q;
        int fresh=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]==1){
                fresh++;
            }else if(grid[i][j]==2){
                q.push({i,j});
            }
            }
        }
        if(fresh==0){
            return 0;
        }
        int ans=0;
        while(!q.empty()){
            int n=q.size();
            bool effect=false;
            for(int i=0;i<n;i++){
                int xin=q.front().first;
                int yin=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int x=dir[i].first;
                    int y=dir[i].second;
                    if(xin-x>=0 && xin-x<grid.size() && yin-y >=0 && yin-y<grid[0].size()){
                        if(grid[xin-x][yin-y]==1){
                            grid[xin-x][yin-y]=2;
                            q.push({xin-x,yin-y});
                            fresh--;
                            effect=true;
                        }
                    }
                }
            }
            
            if(effect==true){
                ans++;
            }
        }
        return fresh == 0 ? ans : -1;
    }
};