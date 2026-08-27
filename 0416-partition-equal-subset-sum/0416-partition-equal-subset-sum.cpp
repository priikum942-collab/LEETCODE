class Solution {
public:
    // bool solve(vector<int>& nums, int sum, int ind, vector<vector<int>>& dp) {
    //     if (sum == 0) {
    //         return true;
    //     }

    //     if (ind == 0) {
    //         if (sum == nums[0]) {
    //             return true;
    //         }

    //         return false;
    //     }
    //     if (dp[ind][sum] != -1) {
    //         return dp[ind][sum];
    //     }
    //     bool take = false;
    //     if (nums[ind] <= sum) {
    //         take = solve(nums, sum - nums[ind], ind - 1, dp);
    //     }
    //     bool not_take = solve(nums, sum, ind - 1, dp);

    //     return dp[ind][sum] = take || not_take;
    // }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalsum = 0;
        for (int i = 0; i < n; i++) {
            totalsum += nums[i];
        }

        if (totalsum % 2 != 0) {
            return false;
        }

        int sum = totalsum / 2;
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        if(nums[0]<=sum)
        dp[0][nums[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int k = 1; k <= sum; k++) {
                bool take = false;
                if (nums[i] <= k) {
                    take = dp[i - 1][ k - nums[i]];
                }
                bool not_take =dp[i - 1][ k ];
                dp[i][k] = take || not_take;
            }
        }
        return dp[n - 1][sum];
    }
};