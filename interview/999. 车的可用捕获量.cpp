class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int ans = 0;
        for(int i = 0; i < 8; ++i) {
            for(int j = 0; j < 8; ++j) {
                if(board[i][j] == 'R') {
                    int ti = i, tj = j;
                    while(ti != 0) {
                        --ti;
                        if(board[ti][tj] == 'p') {
                            ans += 1;
                            break;
                        }
                        else if(board[ti][tj] == 'B')
                            break;
                    }

                    ti = i;
                    while(ti != 7) {
                        ++ti;
                        if(board[ti][tj] == 'p') {
                            ans += 1;
                            break;
                        }
                        else if(board[ti][tj] == 'B')
                            break;
                    }

                    ti = i;
                    while(tj != 0) {
                        --tj;
                        if(board[ti][tj] == 'p') {
                            ans += 1;
                            break;
                        }
                        else if(board[ti][tj] == 'B')
                            break;
                    }
                    tj = j;
                    while(tj != 7) {
                        ++tj;
                        if(board[ti][tj] == 'p') {
                            ans += 1;
                            break;
                        }
                        else if(board[ti][tj] == 'B')
                            break;
                    }
                    return ans;
                }
            }
        }
        return ans;
    }
};