class Solution {
public:
    // int maxi = -1e9; if asked across all paths 
    int solve(vector<vector<int>>& grid,int r,int c1,int c2, vector<vector<vector<int>>>&dp)
    {
        int n = grid.size();
        int m = grid[0].size();

        //out of bounds check 
        if(c1<0 || c2<0 || c1>=m||c2>=m)
        {
            return -1e7;
        }
        //base-case 
        if(r==n-1)
        {
            //if same cell 
            if(c1==c2)
            {
                return grid[r][c1];
            }

            return grid[r][c1] + grid[r][c2];
        }
        if(dp[r][c1][c2]!=-1)
        {
            return dp[r][c1][c2];
        }
         int maxi = -1e9;
        //as for each move of alice there will be 3 moves for bob
        //these are directiions
        for(int i = -1;i<=1;i++)
        {
            int cherry = 0;
            for(int j=-1;j<=1;j++)
            {
                //same cell 
                if(c1==c2)
                {
                    cherry = grid[r][c1];
                }
                else
                {
                    cherry = grid[r][c1] + grid[r][c2];
                }
                //recursion call 
                cherry += solve(grid,r+1,c1+i,c2+j,dp);
                maxi = max(maxi,cherry);
            }
        }

        return dp[r][c1][c2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        //3 parameters in recursion 
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        // recursion call
        return solve(grid, 0, 0, m - 1,dp); // row,col1,col2
    }
};