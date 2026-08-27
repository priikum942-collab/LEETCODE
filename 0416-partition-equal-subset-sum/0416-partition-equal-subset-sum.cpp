class Solution {
public:
    bool solve(vector<int>& nums,int sum,int ind, vector<vector<int>>&dp)
    {
        if(sum==0)
        {
            return true;
        }

        if(ind == 0)
        {
            if(sum == nums[0])
            {
                return true;
            }

            return false;
        }
        if(dp[ind][sum]!=-1)
        {
            return dp[ind][sum];
        }
        bool take = false;
        if(nums[ind]<=sum)
        {
            take = solve(nums,sum-nums[ind],ind-1,dp);
        }
        bool not_take =  solve(nums,sum,ind-1,dp);

        return dp[ind][sum] = take || not_take;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalsum = 0;
        for(int i=0;i<n;i++)
        {
            totalsum += nums[i];
        }

        if(totalsum % 2 !=0)
        {
            return false;
        }

        int sum = totalsum/2;
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return solve(nums,sum,n-1,dp);
    }
};