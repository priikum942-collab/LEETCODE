class Solution {
public:
    // int solve(vector<vector<int>>& grid,int r,int c, vector<vector<int>>&dp)
    // {
    //     //base-case
    //     if(r==0 && c==0)
    //     {
    //         return grid[0][0];
    //     }

    //     if(r<0 || c<0)
    //     {
    //         return 1000000;
    //     }
    //     if(dp[r][c]!=-1)
    //     {
    //         return dp[r][c];
    //     }
    //     int up = grid[r][c] + solve(grid,r-1,c,dp);
    //     int left =  grid[r][c] + solve(grid,r,c-1,dp);

    //     return dp[r][c] = min(up,left);

    // }
    int minPathSum(vector<vector<int>>& grid) {
        int n= grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        //base-case
        dp[0][0] = grid[0][0];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 && j==0) continue;
                int up = grid[i][j];
                if(i>0)
                {
                    up +=dp[i-1][j];
                }
                else
                {
                    up += 1e9;
                }
                int left = grid[i][j];
                if(j>0)
                {
                    left += dp[i][j-1];
                }
                else
                {
                    left += 1e9;
                }
                dp[i][j] = min(up,left);
            }
        }
        return dp[n-1][m-1];
    }
};