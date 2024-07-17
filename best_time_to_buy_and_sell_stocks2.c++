class Solution {
public:
    int solve(vector<int>&prices, int index ,bool k,vector<vector<int>>&dp){
        // we can ether hold , sell or buy
        if(index==prices.size()){
            return 0;
        }
        if(dp[index][k]!=-1){
            return dp[index][k];
        }
        if(k==true){
            //ek kharida hua hai
            int sell=prices[index]+solve(prices,index+1,false,dp);
            int hold=solve(prices,index+1,true,dp);
            return dp[index][k]= max(sell,hold);
        }else{
            int buy=-prices[index]+solve(prices,index+1,true,dp);
            int hold=solve(prices,index+1,false,dp);
            return dp[index][k]= max(buy,hold);
        }

    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return solve(prices,0,false,dp);
    }
    // i am a dp bully, and i can easily do it using tabulation and space optimisation too
};
