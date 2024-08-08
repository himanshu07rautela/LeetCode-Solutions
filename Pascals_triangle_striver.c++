class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // 1 , (1,1),(1,2,1),(1,3,3,1)
        vector<vector<int>>ans;
        vector<int>prev;
        prev.push_back(1);

        ans.push_back(prev);
        if(numRows==1){
            return ans;
        }
        for(int i=1;i<numRows;i++){
            int n=prev.size()+1;
            vector<int>curr(n);
            curr[0]=1;
            curr[n-1]=1;
            for(int j=1;j<curr.size()-1;j++){
                curr[j]=prev[j]+prev[j-1];
            }
            ans.push_back(curr);
            prev=curr;
        }
        return ans;

    }
};