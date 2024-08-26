/*---------------------------recur+memo----------------------------------------------

class Solution {
public:
        int helper(int i, int buy, vector<int>&prices, int n, int cnt,vector<vector<vector<int>>>&dp){
        //base caes
        if(i==n)return 0;
        if(cnt==0)return 0;

        if(dp[i][buy][cnt]!=-1)return dp[i][buy][cnt];

        long profit;
        if(buy){
            int inc = -prices[i] + helper(i+1, 0, prices,n,  cnt,dp);
            int exc = 0 + helper(i+1, 1, prices,n, cnt,dp);
            profit = max(inc,exc);
        }
        else{
            int inc = prices[i] + helper(i+1, 1, prices,n, cnt-1,dp);
            int exc = 0 + helper(i+1, 0, prices,n, cnt,dp);
            profit = max(inc,exc);
        }
        return dp[i][buy][cnt] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2,vector<int>(k+1,-1)));
        return helper(0, 1, prices, n,k,dp);
    }
};

---------------------------------tabulation--------------------------------------
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2,vector<int>(k+1,0)));
        
        // no need to write base cases because for base cases ans will be 0 that we have already initialised in the dp array

        for(int i = n-1;i>=0;i--){
            for(int buy = 0;buy<=1;buy++){
                for(int cnt = 1; cnt<=k; cnt++){
                    long profit;
                    if(buy){
                        int inc = -prices[i] + dp[i+1][0][cnt];
                        int exc = 0 + dp[i+1][1][cnt];
                        profit = max(inc,exc);
                    }
                    else{
                        int inc = prices[i] + dp[i+1][1][cnt-1];
                        int exc = 0 + dp[i+1][0][cnt];
                        profit = max(inc,exc);
                    }
                    dp[i][buy][cnt] = profit;
                }
            }
        }
        return dp[0][1][k];
    }
};

-----------------------------------space obtimised dp---------------------------------*/
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>>next(2,vector<int>(k+1,0));
        vector<vector<int>>cur(2,vector<int>(k+1,0));
        // no need to write base cases because for base cases ans will be 0 that we have already initialised in the dp array

        for(int i = n-1;i>=0;i--){
            for(int buy = 0;buy<=1;buy++){
                for(int cnt = 1; cnt<=k; cnt++){
                    long profit;
                    if(buy){
                        int inc = -prices[i] + next[0][cnt];
                        int exc = 0 + next[1][cnt];
                        profit = max(inc,exc);
                    }
                    else{
                        int inc = prices[i] + next[1][cnt-1];
                        int exc = 0 + next[0][cnt];
                        profit = max(inc,exc);
                    }
                    cur[buy][cnt] = profit;
                }
            }
            next = cur;
        }
        return next[1][k];
    }
};
