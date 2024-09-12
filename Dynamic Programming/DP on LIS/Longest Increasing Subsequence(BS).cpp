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
    int longestSubsequence(int n, int nums[])
    {
       // your code here
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
