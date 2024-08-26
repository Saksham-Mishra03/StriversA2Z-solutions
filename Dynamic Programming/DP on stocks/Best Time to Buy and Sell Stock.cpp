class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int profit = INT_MIN;

        for(int i =1;i<prices.size();i++){
            profit = max(profit,prices[i]-mini);
            mini = min(mini,prices[i]);
        }
        if(profit<0)return 0;
        else return profit;
    }
};
