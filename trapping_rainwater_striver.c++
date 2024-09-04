class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>prefixhigh(height.size());
        vector<int>suffixhigh(height.size());
        prefixhigh[0]=height[0];
        int maxi=height[0];
        for(int i=1;i<height.size();i++){
            prefixhigh[i] = max(prefixhigh[i - 1], height[i]);
        }
        maxi=height[height.size()-1];
        suffixhigh[height.size()-1]=height[height.size()-1];
        for(int i=height.size()-2;i>=0;i--){
            suffixhigh[i]=max(suffixhigh[i+1],height[i]);
        }
         int waterTrapped = 0;
        for (int i = 0; i < height.size(); i++) {
            waterTrapped += min(prefixhigh[i], suffixhigh[i]) - height[i];
        }
        return waterTrapped;
    }
};