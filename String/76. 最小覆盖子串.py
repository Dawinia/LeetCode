class Solution:
    def minWindow(self, s: str, t: str) -> str:
        ss, ts = len(s), len(t)
        if ss < 1 or ts < 1 or ts > ss: return ""

        tc, sc = {}, {}
        for c in t:
            tc[c] = tc[c] + 1 if c in tc else 1
            sc[c] = 0
        
        start = i = j = count = 0
        ans = float('inf')
        while j < ss:
            c = s[j]
            j += 1
            if c in sc:
                sc[c] += 1
                if sc[c] == tc[c]:
                    count += 1
            while count == len(tc):
                if j - i < ans:
                    ans = j - i
                    start = i
                d = s[i]
                i += 1
                if d in sc:
                    if sc[d] == tc[d]:
                        count -= 1
                    sc[d] -= 1

        return "" if ans == float('inf') else s[start: start + ans]
