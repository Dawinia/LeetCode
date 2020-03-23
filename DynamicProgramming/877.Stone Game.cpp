class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
    bool stoneGame(vector<int>& piles) {
        vector<vector<pair<int, int>>> dp;
        int size = piles.size();

        // for(int i = 0; i < size; ++i) {
        //     dp[i][i].first = piles[i];
        //     dp[i][i].second = 0;
        // }
        vector<pair<int, int> > row;
        for(int i = 0; i < size; ++i) {
            for(int j = 0; j < size; ++j) {
                if(i == j) {
                    row.emplace_back(make_pair(piles[i], 0));
                }
                else
                    row.emplace_back(make_pair(0, 0));
            }
            dp.emplace_back(row);
            row.clear();
        }
        for(int l = 2; l < size; ++l) {
            for(int i = 0; i < size - l; ++i) {
                int j = l + i - 1;
                int first = piles[i] + dp[i + 1][j].second;
                int second = piles[j] + dp[i][j - 1].second;
                if(first > second) {
                    dp[i][j].first = second;
                    dp[i][j].second = dp[i + 1][j].first;
                }
                else {
                    dp[i][j].first = first;
                    dp[i][j].second = dp[i][j - 1].first;
                }
            }
        }
        return dp[0][size - 1].first - dp[0][size - 1].second >= 0;
    }
};