class Solution {
public:
    int sumOfDigits(int i, int j) {
        int sum = 0;
        while(i != 0 || j != 0) {
            sum += i % 10;
            sum += j % 10;
            i /= 10;
            j /= 10;
        }
        return sum;
    }

    int movingCount(int m, int n, int k) {
        if(m * n == 0) {
            return min(max(m, n), k) + 1;
        }
        if(k == 0)
            return 1;
        queue<pair<int, int> > q;
        vector<vector<int> > visited(m, vector<int>(n, 0));
        vector<pair<int, int> > dires = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        q.push(make_pair(0, 0));
        visited[0][0] = 1;

        int ans = 1;
        while(!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            for(int i = 0; i < 4; ++i) {
                int nx = cur.first + dires[i].first;
                int ny = cur.second + dires[i].second;
                if(nx < m && nx >= 0 && ny < n && ny >= 0 && visited[nx][ny] == 0) {
                    if(sumOfDigits(nx, ny) <= k) {
                        ++ans;
                        q.push(make_pair(nx, ny));
                        visited[nx][ny] = 1;
                    }
                }
            }
        }
        return ans;
    }
};