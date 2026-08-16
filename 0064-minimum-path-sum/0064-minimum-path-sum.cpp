class Solution {
public:
    int solve(vector<vector<int>>& grid,int r,int c, vector<vector<int>>&dp)
    {
        //base-case
        if(r==0 && c==0)
        {
            return grid[0][0];
        }

        if(r<0 || c<0)
        {
            return 1000000;
        }
        if(dp[r][c]!=-1)
        {
            return dp[r][c];
        }
        int up = grid[r][c] + solve(grid,r-1,c,dp);
        int left =  grid[r][c] + solve(grid,r,c-1,dp);

        return dp[r][c] = min(up,left);

    }
    int minPathSum(vector<vector<int>>& grid) {
        int n= grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(grid,n-1,m-1,dp);
    }
};