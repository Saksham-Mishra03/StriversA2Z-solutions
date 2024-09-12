class Solution {
public:
/* -----------recursive solution-------------------------------------------------

    int recur(vector<int>&nums, int ind, int pre)
    {
        if(ind>=nums.size())
        return 0;
        int inc = 0;
        if(nums[ind]>pre)
       inc =  1+ recur(nums,ind+1, nums[ind]);

       int exc = recur(nums,ind+1,pre);
       return max(inc,exc);
    }

    int lengthOfLIS(vector<int>& nums) {
        int pre=-1;
        int ind  = 0;
        return recur(nums,ind,INT_MIN);
    }
*/
/*---------------------------------- recur + memo ---------------------------------------------

    int recur(vector<int>&nums, int ind, int pre, vector<vector<int>> &dp)
    {
        if(ind>=nums.size())
        return 0;
        if(dp[ind][pre+1]!=-1) return dp[ind][pre+1];

        int inc = 0;
        if(pre==-1 || nums[ind]>nums[pre])
        inc =  1+ recur(nums,ind+1, ind ,dp);

        int exc = recur(nums,ind+1,pre,dp);
        dp[ind][pre+1] =  max(inc,exc);
        return dp[ind][pre+1];

    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        int pre=-1;
        int ind  = 0;
        return recur(nums,ind,pre,dp);
    }

    */

    //------------------- tabulation--------------------------------------------------------
/*
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>dp(n);

        dp[0] = 1;
        //dp[i] store the lis till i index
        int ans = 1;
        for(int i = 1;i<n;i++)
        {
            int maxlissize = 0;
            //ab hm i se phle k sare element dhunege  and jo max hoga usse ith ko compare krege
            for(int j = 0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    maxlissize = max(maxlissize,dp[j]);
                }
            }
            dp[i] = maxlissize+1;
            ans = max(ans,dp[i]);
        }
        return ans;
    }
    */

    /*-----------------------------------------------------------*/

    int bs(int x,vector<int>ar)
    {
        int l = 0;
        int r = ar.size()-1;
        int ans;
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            if(ar[mid]<x)
            l = mid+1;

            else
            {
                ans = mid;
                r = mid-1;
            }
        }
        return ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>storelis;
        storelis.push_back(nums[0]);

        for(int i = 1;i<n;i++)
        {
            if(nums[i]>storelis[storelis.size()-1])
            {
                storelis.push_back(nums[i]);
            }
            else
            {
                int idx = bs(nums[i],storelis);
                storelis[idx] = nums[i];
            }
        }
        return storelis.size();
    }

};
