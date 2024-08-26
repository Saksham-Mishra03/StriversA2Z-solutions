/*--------------------------------- recursion+memo ----------------------------------

class Solution {
public:
    int helper(int i, int buy, vector<int>&prices,int n,vector<vector<int>>&dp){
        if(i>=n)return 0;

        if(dp[i][buy]!=-1)return dp[i][buy];

        long profit;
        if(buy){
            long inc = -prices[i] + helper(i+1, 0, prices, n, dp);
            long exc = 0 + helper(i+1, 1, prices, n, dp);
            profit = max(inc,exc);
        }
        else{
            long inc = prices[i] + helper(i+2, 1, prices, n, dp);
            long exc = 0 + helper(i+1, 0, prices, n, dp);
            profit = max(inc,exc);
        }
        return dp[i][buy]= profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return helper(0,1,prices,n,dp);
    }
};

----------------------------------------------------------------------*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));

        dp[n][0] = dp[n][1] = 0;

        for(int i = n-1;i>=0;i--){
            for(int buy = 0;buy<=1;buy++){
                long profit = 0;

                if(buy){
                    long inc = -prices[i] + dp[i+1][0];
                    long exc = 0 + dp[i+1][1];
                    profit = max(inc,exc);
                }
                else{
                    long inc = prices[i] + dp[i+2][1];
                    long exc = 0 + dp[i+1][0];
                    profit = max(inc,exc);
                }
                dp[i][buy] = profit;
            }
                        
        }
        return dp[0][1];        
    }
};
