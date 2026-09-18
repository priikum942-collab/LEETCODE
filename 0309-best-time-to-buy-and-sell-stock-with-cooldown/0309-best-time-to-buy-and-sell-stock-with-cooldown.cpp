class Solution {
public:
    int solve(vector<int>& prices, int day, int n, bool buy,
              vector<vector<int>>& dp) {

        if (day >= n)
            return 0;

        if (dp[day][buy] != -1)
            return dp[day][buy];

        if (buy) {
            int take = solve(prices, day + 1, n, false, dp) - prices[day];
            int notTake = solve(prices, day + 1, n, true, dp);

            return dp[day][buy] = max(take, notTake);
        } 
        else {
            int sell = prices[day] + solve(prices, day + 2, n, true, dp);
            int notSell = solve(prices, day + 1, n, false, dp);

            return dp[day][buy] = max(sell, notSell);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return solve(prices, 0, n, true, dp);
    }
};