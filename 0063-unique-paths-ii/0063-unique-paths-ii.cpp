class Solution {
public:
    int solve(vector<vector<int>>&grid,int row,int col, vector<vector<int>>&dp)
    {
        if(row<0 || col <0)
        {
            return 0;
        }

        if(grid[row][col] == 1)
        {
            return 0;
        }

        if(row==0 && col ==0)
        {
            //reached destination 
            return 1;
        }
        if(dp[row][col]!=-1)
        {
            return dp[row][col];
        }
        int up = solve(grid,row-1,col,dp);
        int left = solve(grid,row,col-1,dp);


        // int up = 0;
        // if(row >= 1 && grid[row-1][col] == 0)
        // {
        //     up = solve(grid,row-1,col,dp);
        // }
        // int left = 0;
        // if(col >= 1 && grid[row][col-1]==0)
        // {
        //     left = solve(grid,row,col-1,dp);
        // }

        return dp[row][col] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>&grid) {
        int n = grid.size();
        int m = grid[0].size();
        // if(grid[n-1][m-1]==1 || grid[0][0]==1)
        // {
        //     return 0;
        // }
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(grid,n-1,m-1,dp);
    }
};