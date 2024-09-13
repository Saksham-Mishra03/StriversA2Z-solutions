class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(n,1),index(n);
        
        sort(nums.begin(),nums.end());
        for(int i= 0;i<n;i++){
            index[i] = i;
            for(int j = 0;j<i;j++){
                if(nums[i]%nums[j]==0  && dp[i]<dp[j]+1){
                    index[i] = j;
                    dp[i]  = 1+ dp[j];
                }
            }
        }
        int maxi = -1, last=-1;
        for(int i= 0;i<n;i++){
            if(maxi<dp[i]){
                maxi = dp[i];
                last = i;
            }
        }
        vector<int>res;
        res.push_back(nums[last]);
        while(last!=index[last]){
            last = index[last];
            res.push_back(nums[last]);
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};
