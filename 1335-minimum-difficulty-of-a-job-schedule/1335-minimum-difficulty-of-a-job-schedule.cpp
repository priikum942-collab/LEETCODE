class Solution {
public:
    int solve(vector<int>& nums, int d, int ind, vector<vector<int>>&dp) {
        int n = nums.size();
        if (d == 1) {
            int maxi = INT_MIN;
            for (int i = ind; i < n; i++) {
                maxi = max(maxi, nums[i]);
            }
            return maxi;
        }
        if(dp[ind][d]!=-1)
        {
            return dp[ind][d];
        }
        // n-d as each job must have 1 day
        int maxx = INT_MIN;
        int final = INT_MAX;
        for (int i = ind; i <= n - d; i++) {
            // FIND MAXDIFFICULTY
            maxx = max(maxx, nums[i]);

            // store it
            int result = maxx + solve(nums, d - 1, i + 1,dp);

            // find min
            final = min(result, final);
        }
        return dp[ind][d] = final;
    }
    int minDifficulty(vector<int>& nums, int d) {
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(d + 1, -1));

        // call recursion
        int ans = solve(nums, d, 0,dp);

        if (ans == INT_MAX) {
            return -1;
        }

        return ans;
    }
};