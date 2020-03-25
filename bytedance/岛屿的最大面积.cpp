class Solution {
public:
    int n, m;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        if(n == 0)
            return 0;
        m = grid[0].size();
        if(m == 0)
            return 0;
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] == 1) {
                    ans = max(dfs(grid, i, j), ans);
                }
            }
        }
        return ans;
    }
    
    int dfs(vector<vector<int>>& grid, int i, int j) {
        vector<pair<int, int> > directions = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };
        int ans = 1;
        
        grid[i][j] = 0;
        
        for(int k = 0; k < 4; ++k) {
            int ni = i + directions[k].first;
            int nj = j + directions[k].second;
            
            if(ni < n && ni >=0 && nj < m && nj >= 0 && grid[ni][nj] == 1)
                ans += dfs(grid, ni, nj);
        }
        return ans;        
    }
};