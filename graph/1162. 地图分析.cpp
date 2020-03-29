class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n <= 2)
            return -1;
        queue<pair<int, int> > q, q1;
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 1)
                    q.push({i, j - 1}), q.push({i - 1, j}), q.push({i, j + 1}), q.push({i + 1, j});
            }
        }
        while(!q.empty()) {
            ++ans;
            while(!q.empty()) {
                int i = q.front().first, j = q.front().second;
                q.pop();
                if(i < n && j < n && i >= 0 && j >= 0 && grid[i][j] == 0) {
                    grid[i][j] = ans;
                    q1.push({i, j - 1}), q1.push({i - 1, j}), q1.push({i, j + 1}), q1.push({i + 1, j});
                }
            }
            swap(q1, q);
        }
        return ans == 1 ? -1 : ans - 1;
    }
};