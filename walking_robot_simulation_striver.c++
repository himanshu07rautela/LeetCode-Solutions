struct pair_hash {
    template <class T1, class T2>
    size_t operator () (const pair<T1, T2> &pair) const {
        return hash<T1>()(pair.first) ^ hash<T2>()(pair.second);
    }
};

class Solution {
public:
    
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // command is either 1 to 9 or -1 and -2;
        // -1 is for turn right and -2 is for left;
        int x = 0;
        int y = 0;
        int gans=INT_MIN;
        unordered_map<pair<int, int>, bool, pair_hash> mp;
        for(int i = 0; i < obstacles.size(); i++){
            int a = obstacles[i][0];
            int b = obstacles[i][1];
            pair<int,int> p = make_pair(a, b);
            mp[p] = true;
        }
        int up = 1;
        int down = 0;
        int left = 0;
        int right = 0;
        for(int i = 0; i < commands.size(); i++){
            // initially go up;

            if(up == 1){
                if(commands[i] == -1){
                    up = 0;
                    right = 1;
                }else if(commands[i] == -2){
                    up = 0;
                    left = 1;
                }else{
                    // move forward
                    for(int j = 0; j < commands[i]; j++){ 
                        if(mp.find(make_pair(x, y + 1)) != mp.end() && mp[make_pair(x, y + 1)] == true){
                           break;
                        }else{
                            y++;
                        }
                    }
                    gans=max(gans,(x*x+(y*y)));
                }

            }else if(down == 1){
                if(commands[i] == -1){
                    down = 0;
                    left = 1;
                }else if(commands[i] == -2){
                    down = 0;
                    right = 1;
                }else{
                    for(int j = 0; j < commands[i]; j++){ 
                        if(mp.find(make_pair(x, y - 1)) != mp.end() && mp[make_pair(x, y - 1)] == true){
                           break;
                        }else{
                            y--;
                        }
                    }
                     gans=max(gans,(x*x+(y*y)));
                }

            }else if(left == 1){
                if(commands[i] == -1){
                    left = 0;
                    up = 1;
                }else if(commands[i] == -2){
                    left = 0;
                    down = 1;
                }else{
                    for(int j = 0; j < commands[i]; j++){ 
                        if(mp.find(make_pair(x - 1, y)) != mp.end() && mp[make_pair(x - 1, y)] == true){
                           break;
                        }else{
                            x--;
                        }
                    }
                     gans=max(gans,(x*x+(y*y)));
                }

            }else if(right == 1){
                if(commands[i] == -1){
                    right = 0;
                    down = 1;
                }else if(commands[i] == -2){
                    right = 0;
                    up = 1;
                }else{
                    for(int j = 0; j < commands[i]; j++){ 
                        if(mp.find(make_pair(x + 1, y)) != mp.end() && mp[make_pair(x + 1, y)] == true){
                           break;
                        }else{
                            x++;
                        }
                    }
                     gans=max(gans,(x*x+(y*y)));
                }
            }
        }
        return gans=max(gans,(x*x+(y*y)));
    }
};
