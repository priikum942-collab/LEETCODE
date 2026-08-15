class Solution {
    public :
    int count = 0;
    int non_obstacle = 0;
    void solve(vector<vector<int>>& grid, vector<vector<int>>& vis, int r,
              int c) {
        int n = grid.size();
        int m = grid[0].size();

        if(grid[r][c] == 2)
        {
            int cells = 0;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(vis[i][j])
                    {
                        cells++;
                    }
                }
            }

            if(cells ==  non_obstacle + 2)
            {
                count++;
            }
            return;
        }

        vector<int>delrow = {-1,0,1,0};
        vector<int>delcol = {0,-1,0,1};

        for(int i=0;i<4;i++)
        {
            int nr = r + delrow[i];
            int nc = c + delcol[i];

            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]!=-1 && !vis[nr][nc])
            {
                vis[nr][nc] = 1;
                solve(grid,vis,nr,nc);
                vis[nr][nc] = 0;
            }
        }
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        pair<int, int> start;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    start = {i, j};
                } else if (grid[i][j] == 0) {
                    non_obstacle++;
                }
            }
        }
        vis[start.first][start.second] = 1;
        solve(grid, vis, start.first, start.second);

        return count;
    }
};