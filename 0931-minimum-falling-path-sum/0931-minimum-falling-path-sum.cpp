class Solution {
public:
    int solve(vector<vector<int>>& matrix, int row, int col,vector<vector<int>>&dp) {
        int n = matrix.size();
        if (col < 0 || col >= n)
            return 1e9;
        if (row == 0) {
            //     int l = 1e9;
            //     if(prev_col>0)
            //     {
            //         l = matrix[1][prev_col-1];
            //     }

            //     int u = matrix[1][prev_col];
            //     int r = 1e9;
            //     if(prev_col<n-1)
            //     {
            //         r = matrix[1][prev_col+1];
            //     }
            //     return min({l,u,r});

            return matrix[row][col];
        }

        if(dp[row][col]!=INT_MAX)
        {
            return dp[row][col];
        }
        int up = matrix[row][col] + solve(matrix, row - 1, col, dp);
        int left_dg = matrix[row][col] + solve(matrix, row - 1, col - 1,dp);
        int right_dg = matrix[row][col] + solve(matrix, row - 1, col + 1, dp);

        return dp[row][col] = min({up, left_dg, right_dg});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mini = 1e9;
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        for (int i = 0; i < n; i++) {
            int ans = solve(matrix, n - 1, i,dp);
            mini = min(ans, mini);
        }

        return mini;
    }
};