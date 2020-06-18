class Solution:
    def reverseParentheses(self, s: str) -> str:
        if not s: return ""

        left, pairs = [], {}
        size = len(s)

        for i in range(size):
            if s[i] == '(':
                left.append(i)
            elif s[i] == ')':
                j = left.pop()
                pairs[i], pairs[j] = j, i
        
        i, d = 0, 1
        ans = ""
        while i < size:
            if s[i] in "()":
                i = pairs[i]
                d = -d
            else:
                ans += s[i]
            i += d
        return ans

####################################################

class Solution:
    def reverseParentheses(self, s: str) -> str:
        if not s: return ""

        stack = []

        for c in s:
            if c == ')':
                tmp = []
                while stack and stack[-1] != '(':
                    tmp.append(stack.pop(-1))
                if not stack:
                    return ""
                stack.pop(-1)
                stack += tmp
                continue
            stack.append(c)
        return "".join(stack)
