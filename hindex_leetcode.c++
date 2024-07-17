class Solution {
public:
    int hIndex(vector<int>& citations) {
        // The h-index is defined as the maximum value of h such that the given researcher 
        // has published at least h papers that have each been cited at least h times.
        if(citations.size()==1){
            if(citations[0]>=1){
                return 1;
            }else{
                return 0;
            }
        }
        int ans=0;
        sort(citations.begin(),citations.end());
        for(int i=0;i<citations.size();i++){
            int m=citations.size()-i;
            if(citations[i]>= m ){
                ans=max(ans,m);
            }
           
        }

        return ans;


    }
};