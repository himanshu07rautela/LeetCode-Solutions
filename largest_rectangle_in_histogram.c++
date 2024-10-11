class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=0;
        vector<int>leftmin(heights.size());
        vector<int>rightmin(heights.size());
        stack<int>stl;
        stl.push(-1);
        for(int i=0;i<heights.size();i++){
            while(stl.top()!=-1 && heights[stl.top()]>=heights[i]){
                stl.pop();
            }
            
            leftmin[i]=stl.top();
            stl.push(i);

        }
        stack<int>str;
        str.push(-1);
        for(int i=heights.size()-1;i>=0;i--){
            while(str.top()!=-1 && heights[str.top()]>=heights[i]){
                str.pop();
            }
            
            rightmin[i]=str.top();
            str.push(i);
        }
        
        for(int i=0;i<heights.size();i++){
            int l=heights[i];
            if(rightmin[i]==-1){
                rightmin[i]=heights.size();
            }
            int w=rightmin[i]-leftmin[i]-1;
            ans=max(ans,l*w);

        }
        
        return ans;
    }
};