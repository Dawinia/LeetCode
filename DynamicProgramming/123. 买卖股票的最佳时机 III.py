class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        i20 = i10 = 0
        i21 = i11 = float('-inf')
        for i in range(len(prices)):
            i20 = max(i20, i21 + prices[i])
            i21 = max(i21, i10 - prices[i])
            i10 = max(i10, i11 + prices[i])
            i11 = max(i11, -prices[i])
        
        return i20