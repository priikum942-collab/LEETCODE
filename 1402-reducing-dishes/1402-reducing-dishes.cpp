class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(vector<int>& satisfaction, int i, int t) {
        if (i >= n) {
            return 0;
        }

        if (dp[i][t] != -1) {
            return dp[i][t];
        }

        int include = satisfaction[i] * t
                    + solve(satisfaction, i + 1, t + 1);

        int exclude = solve(satisfaction, i + 1, t);

        return dp[i][t] = max(include, exclude);
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        n = satisfaction.size();

        sort(satisfaction.begin(), satisfaction.end());

        dp.assign(n, vector<int>(n + 2, -1));

        return solve(satisfaction, 0, 1);
    }
};