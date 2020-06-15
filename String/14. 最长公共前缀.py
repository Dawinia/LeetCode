class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        def lcp(i, j):
            if i == j:
                return strs[i]
            mid = i + (j - i) // 2
            left, right = lcp(i, mid), lcp(mid + 1, j)
            minLen = min(len(left), len(right))
            for k in range(minLen):
                if left[k] != right[k]:
                    return left[:k]
            return left[:minLen]
        
        return "" if not strs else lcp(0, len(strs) - 1)