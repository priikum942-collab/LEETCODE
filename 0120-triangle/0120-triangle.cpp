class Solution {
public: 
    // int solve(vector<vector<int>>& triangle,int r,int c,vector<vector<int>>&dp)
    // {
    //     int n = triangle.size();
    //     if(r >=n || c >= r+1)
    //     {
    //         return 0;
    //     }
    //     if(r == n-1)
    //     {
    //         return triangle[r][c];
    //     }
    //     if(dp[r][c]!=1e9)
    //     {
    //         return dp[r][c];
    //     }
    //     int down = triangle[r][c] + solve(triangle,r+1,c,dp);
    //     int right = triangle[r][c] +  solve(triangle,r+1,c+1,dp);

    //     return dp[r][c] = min(down,right);
    // }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int k=0;k<n;k++)
        {
            dp[n-1][k] = triangle[n-1][k];
        }
        //here we grom from down to up 
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                int down = triangle[i][j] + dp[i+1][j];

                int right = triangle[i][j];
                if(j<n-1)
                {
                    right += dp[i+1][j+1];
                }

                dp[i][j] = min(down,right);
            }
        }
        return dp[0][0];
    }
};