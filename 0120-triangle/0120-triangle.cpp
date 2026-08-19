class Solution {
public:
    // int solve(vector<vector<int>>& triangle, int row, int col_ind,
    //           vector<vector<int>>& dp) {
    //     if (row == 0) {
    //         return triangle[0][0];
    //     }
    //     if (row < 0 || col_ind < 0) {
    //         return 1e9;
    //     }
    //     if (col_ind > row) {
    //         return 1e9;
    //     }
    //     if (dp[row][col_ind] != -1) {
    //         return dp[row][col_ind];
    //     }
    //     int up = triangle[row][col_ind] + solve(triangle, row - 1, col_ind, dp);
    //     int left =
    //         triangle[row][col_ind] + solve(triangle, row - 1, col_ind - 1, dp);

    //     return dp[row][col_ind] = min(up, left);
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int last_row = triangle[n - 1].size();
        int mini = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i; j++) {

                int up = triangle[i][j] + dp[i - 1][j];
                int left = triangle[i][j];
                if(j>0)
                {
                    left += dp[i - 1][j - 1];
                }
        
                if (j == 0) {
                    // at 0 only one direction available
                    dp[i][j] = up;
                }
                else if (j == i) {
                    // same here
                    dp[i][j] = left;
                } else {
                    dp[i][j] = min(up, left);
                }
            }
        }
        for (int i = 0; i < last_row; i++) {
            int ans = dp[n-1][i];
            mini = min(mini, ans);
        }

        return mini;
    }
};