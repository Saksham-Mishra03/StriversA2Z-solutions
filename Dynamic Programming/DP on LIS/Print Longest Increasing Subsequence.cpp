    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        vector<int>dp(n,1),hash(n);
        int maxi = 1, last = 0;
        
        for(int i = 0;i<n;i++){
            hash[i] = i;
            for(int j = 0;j<i;j++){
                if(arr[j]<arr[i] && 1+dp[j]>dp[i]){
                    dp[i] = 1+dp[j];
                    hash[i] = j;
                }
            }
            if(dp[i]>maxi){
                maxi = dp[i];
                last = i;
            }
        }
        vector<int>ans;
        ans.push_back(arr[last]);
        while(hash[last]!=last){
            last = hash[last];
            ans.push_back(arr[last]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
