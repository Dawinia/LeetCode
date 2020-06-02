class Solution:
    def decodeString(self, s: str) -> str:
        stack, ans, times = [], "", 0
        for c in s:
            if c == '[':
                stack.append((times, ans))
                ans, times = "", 0
            elif c == ']':
                cur_times, last_ans = stack.pop()
                ans = last_ans + cur_times * ans
            elif c.isdigit():
                times = times * 10 + int(c)            
            else:
                ans += c
        return ans