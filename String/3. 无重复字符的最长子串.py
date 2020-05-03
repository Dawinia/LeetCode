from collections import defaultdict
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        d = defaultdict(int)

        ans = left = 0
        for i, ch in enumerate(s):
            if d[ch] == 0 or d[ch] < left:
                ans = max(ans, i - left + 1)
            else:
                left = d[ch]
            d[ch] = i + 1
        return ans