class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //we have a brute force approach, and it doersn't work

        // we have to run 2 arrays one for finding the minimum and maxmum till that point;
        vector<int>minnums(prices.size());//min from 0 to that index
        int mini=INT_MAX;
        for(int i=0;i<prices.size();i++){
            mini=min(mini,prices[i]);
            minnums[i]=mini;
        }
        vector<int>maxnums(prices.size());//min from 0 to that index
        int maxi=INT_MIN;
        for(int i=prices.size()-1;i>=0;i--){
            maxi=max(maxi,prices[i]);
            maxnums[i]=maxi;
        }
        int ans=0;
        for(int i=0;i<prices.size()-1;i++){
            ans=max(ans,(maxnums[i+1]-minnums[i]));
        }
        return ans;


    
    }
};