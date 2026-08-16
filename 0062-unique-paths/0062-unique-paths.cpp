class Solution {
public:
    int solve( vector<vector<int>>&dp,int row,int col)
    {
        //base-case
        if(row == 0 && col == 0)
        {
            return 1;
        }
        
        if(row<0 || col<0)
        {
            return 0;
        }

        if(dp[row][col]!=-1)
        {
            return dp[row][col];
        }
        int up = solve(dp,row-1,col);
        int left = solve(dp,row,col-1);

        return dp[row][col] = up + left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(dp,m-1,n-1);
    }
};