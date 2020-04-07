class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size(), pre;
        vector<int> dp(n + 1, 0);
        for(int i = 1; i <= n; ++i) {
            dp[i] = i;
        }
        for(int i = 1; i <= m; ++i) {
            pre = dp[0];
            dp[0] = i;
            for(int j = 1; j <= n; ++j) {
                int temp = dp[j];
                if(word1[i - 1] == word2[j - 1])
                    dp[j] = pre;
                else
                    dp[j] = min(pre, min(dp[j], dp[j - 1])) + 1;
                pre = temp;
            }
        }
        return dp[n];
    }
};