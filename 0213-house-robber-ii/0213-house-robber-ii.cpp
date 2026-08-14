class Solution {
public:
    int solve(vector<int>& nums,int ind,int end,vector<int>&dp)
    {
        if(ind == end)
        {
            return nums[ind];
        }
        if(dp[ind]!=-1)
        {
            return dp[ind];
        }
        int take = nums[ind];
        if(ind-2>=end)
        {
            take += solve(nums,ind-2,end,dp);
        }
        int skip = 0;
        if(ind > end)
        {
            skip = solve(nums,ind-1,end,dp);
        }

        return dp[ind] = max(take,skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int>dp1(n+1,-1);
        vector<int>dp2(n+1,-1);
        int ans1 = solve(nums,n-2,0,dp1);
        int ans2 = solve(nums,n-1,1,dp2);

        return max(ans1,ans2);
    }
};