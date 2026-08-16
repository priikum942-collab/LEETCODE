class Solution {
public:
    // int solve(vector<vector<int>>&grid,int i,int j,
    // vector<vector<int>>&dp)
    // {
    //     if(i<0 || j <0)
    //     {
    //         return 0;
    //     }

    //     if(grid[i][j] == 1)
    //     {
    //         return 0;
    //     }

    //     // if(i==0 && j ==0)
    //     // {
    //     //     //reached destination
    //     //     return 1;
    //     // }
    //     if(dp[i][j]!=-1)
    //     {
    //         return dp[i][j];
    //     }
    //     int up = solve(grid,i-1,j,dp);
    //     int left = solve(grid,i,j-1,dp);

    // int up = 0;
    // if(i >= 1 && grid[i-1][j] == 0)
    // {
    //     up = solve(grid,i-1,j,dp);
    // }
    // int left = 0;
    // if(j >= 1 && grid[i][j-1]==0)
    // {
    //     left = solve(grid,i,j-1,dp);
    // }

    //     return dp[i][j] = up + left;
    // }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // if(grid[n-1][m-1]==1 || grid[0][0]==1)
        // {
        //     return 0;
        // }
        vector<vector<int>> dp(n, vector<int>(m, 0));
        // 0 as grid with -1 contain 0
        // BASE-CASES

        dp[0][0] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    dp[i][j] = 0;
                }
                if (grid[i][j] == 0) {
                     if (i == 0 && j == 0)
                    continue;
                    int up = 0;
                    if (i >= 1 && grid[i - 1][j] == 0) {
                        up = dp[i - 1][j];
                    }
                    int left = 0;
                    if (j >= 1 && grid[i][j - 1] == 0) {
                        left = dp[i][j - 1];
                    }
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};