class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0, j = 1, size = prices.size();
        int ans = 0;
        if(size < 1)
            return 0;
        while(i < size && j < size) {
            if(prices[i] <= prices[j]) {
                ans = max(ans, prices[j] - prices[i]);
                ++j;
                
            } else {
                ++i;
            }
            if(i > j)
                j = i + 1;
        }
        return ans;
    }
};