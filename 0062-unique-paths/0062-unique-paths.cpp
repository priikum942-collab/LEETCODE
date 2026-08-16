class Solution {
public:
    // int solve( vector<vector<int>>&dp,int row,int col)
    // {
    //     //base-case
    //     if(row == 0 && col == 0)
    //     {
    //         return 1;
    //     }
        
    //     if(row<0 || col<0)
    //     {
    //         return 0;
    //     }

    //     if(dp[row][col]!=-1)
    //     {
    //         return dp[row][col];
    //     }
    //     int up = solve(dp,row-1,col);
    //     int left = solve(dp,row,col-1);

    //     return dp[row][col] = up + left;
    // }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,1));
        
        dp[0][0] = 1;

        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                int up = dp[i-1][j];
                int left = dp[i][j-1];

                dp[i][j] = up + left;
            }
        }

        return dp[m-1][n-1];
    }
};