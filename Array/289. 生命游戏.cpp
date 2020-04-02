class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        if(m == 0)
            return;
        int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};

        int n = board[0].size();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int sum = 0;
                for(int k = 0; k < 8; ++k) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if(ni >= 0 && ni < m && nj >= 0 && nj < n)
                        sum += (board[ni][nj] & 1);
                }

                if(board[i][j] == 1) {
                    if(sum == 2 || sum == 3)
                        board[i][j] |= 2;
                }
                else {
                    if(sum == 3)
                        board[i][j] |= 2;
                }
            }
        }

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                board[i][j] >>= 1;
            }
        }
    }
};