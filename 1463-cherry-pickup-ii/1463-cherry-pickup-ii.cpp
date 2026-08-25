class Solution {
public:
    // // int maxi = -1e9; if asked across all paths
    // int solve(vector<vector<int>>& grid,int r,int c1,int c2,
    // vector<vector<vector<int>>>&dp)
    // {
    //     int n = grid.size();
    //     int m = grid[0].size();

    //     //out of bounds check
    //     if(c1<0 || c2<0 || c1>=m||c2>=m)
    //     {
    //         return -1e7;
    //     }
    //     //base-case
    //     if(r==n-1)
    //     {
    //         //if same cell
    //         if(c1==c2)
    //         {
    //             return grid[r][c1];
    //         }

    //         return grid[r][c1] + grid[r][c2];
    //     }
    //     if(dp[r][c1][c2]!=-1)
    //     {
    //         return dp[r][c1][c2];
    //     }
    //      int maxi = -1e9;
    //     //as for each move of alice there will be 3 moves for bob
    //     //these are directiions
    //     for(int i = -1;i<=1;i++)
    //     {
    //         int cherry = 0;
    //         for(int j=-1;j<=1;j++)
    //         {
    //             //same cell
    //             if(c1==c2)
    //             {
    //                 cherry = grid[r][c1];
    //             }
    //             else
    //             {
    //                 cherry = grid[r][c1] + grid[r][c2];
    //             }
    //             //recursion call
    //             cherry += solve(grid,r+1,c1+i,c2+j,dp);
    //             maxi = max(maxi,cherry);
    //         }
    //     }

    //     return dp[r][c1][c2] = maxi;
    // }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // 3 parameters in recursion
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(m, -1)));

        // base- case convertion
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                if (j1 == j2) {
                    dp[n - 1][j1][j2] = grid[n - 1][j1];
                } else {
                    dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
                }
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {
                    int maxi = -1e9;
                    // 9 possibillities
                    for (int d1 = -1; d1 <= 1; d1++) {
                        int cherry = 0;
                        for (int d2 = -1; d2 <= 1; d2++) {

                            // same cell
                            if (j1 == j2) {
                                cherry = grid[i][j1];
                            } else {
                                cherry = grid[i][j1] + grid[i][j2];
                            }

                            if (j1 + d1 >= 0 && j1 + d1 < m && j2 + d2 >= 0 &&
                                j2 + d2 < m) {
                                cherry += dp[i + 1][j1 + d1][j2 + d2];
                            } 
                            // else {
                            // //     cherry += -1e9;
                            // // }
                            maxi = max(maxi, cherry);
                        }
                    }

                    dp[i][j1][j2] = maxi;
                }
            }
        }

        return dp[0][0][m - 1];
    }
};
