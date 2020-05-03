class Solution:
    def frequencySort(self, s: str) -> str:
        wc = {}
        for c in s:
            if c in wc:
                wc[c] += 1
            else:
                wc[c] = 1
        
        wc=sorted(wc.items(),key=lambda x:x[1],reverse=True)
        ans = ""
        for key in wc:
            ans += key[0] * key[1]
        return ans
