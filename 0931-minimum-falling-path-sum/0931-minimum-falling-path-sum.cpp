class Solution {
public:
    // int solve(vector<vector<int>>& matrix, int row, int col,vector<vector<int>>&dp) {
    //     int n = matrix.size();
    //     if (col < 0 || col >= n)
    //         return 1e9;
    //     if (row == 0) {
    //         return matrix[row][col];
    //     }

    //     if(dp[row][col]!=INT_MAX)
    //     {
    //         return dp[row][col];
    //     }
    //     int up = matrix[row][col] + solve(matrix, row - 1, col, dp);
    //     int left_dg = matrix[row][col] + solve(matrix, row - 1, col - 1,dp);
    //     int right_dg = matrix[row][col] + solve(matrix, row - 1, col + 1, dp);

    //     return dp[row][col] = min({up, left_dg, right_dg});
    // }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mini = 1e9;
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            dp[0][i] = matrix[0][i];
        }
        for(int row = 1;row<n;row++)
        {
            for(int col=0;col<n;col++)
            {
                int up = matrix[row][col] + dp[row-1][col];
                int left_dg = 1e9;
                if(col>0)
                {
                    left_dg = matrix[row][col]+ dp[row-1][col-1];
                }
                int right_dg = 1e9;
                if(col <n-1)
                {
                    right_dg = matrix[row][col] + dp[row-1][col+1];
                }

                dp[row][col] = min({up, left_dg, right_dg});
            }
        }
        for (int i = 0; i < n; i++) {
            int ans = dp[n-1][i];
            mini = min(ans, mini);
        }

        return mini;
    }
};