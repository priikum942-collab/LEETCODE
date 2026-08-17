class Solution {
public: 
    int solve(vector<vector<int>>& triangle,int r,int c,vector<vector<int>>&dp)
    {
        int n = triangle.size();
        if(r >=n || c >= r+1)
        {
            return 0;
        }
        if(r == n-1)
        {
            return triangle[r][c];
        }
        if(dp[r][c]!=1e9)
        {
            return dp[r][c];
        }
        int down = triangle[r][c] + solve(triangle,r+1,c,dp);
        int right = triangle[r][c] +  solve(triangle,r+1,c+1,dp);

        return dp[r][c] = min(down,right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,1e9));
        return solve(triangle,0,0,dp);
    }
};