class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        if not s: return False

        dp = [False for _ in range(len(s) + 1)]
        dp[0] = True
        wordDict = set(wordDict)
        for i in range(len(s) + 1):
            for j in range(i):
                if dp[j] and s[j: i] in wordDict:
                    dp[i] = True
                    break
        return dp[-1]