class Solution {
private:
    int m = 0, n = 0;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        if(n < 1)
            return 0;
        m = grid[0].size();
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
        int ans = 1;
        int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        grid[i][j] = 0;
        for(int k = 0; k < 4; ++k) {
            int ni = i + directions[k][0];
            int nj = j + directions[k][1];

            if(ni < n && ni >= 0 && nj < m && nj >= 0 && grid[ni][nj] == 1)
                ans += dfs(grid, ni, nj);
        }
        return ans;
    }
};