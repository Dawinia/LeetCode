class Solution:
    def minAddToMakeValid(self, S: str) -> int:
        if not S: return 0
        stack = []
        for c in S:
            if c == '(':
                stack.append(c)
            else:
                if stack and stack[-1] == '(':
                    stack.pop()
                else:
                    stack.append(c)

        return len(stack)

##########################################

class Solution:
    def minAddToMakeValid(self, S: str) -> int:
        if not S: return 0
        ans = balance = 0

        for c in S:
            balance += 1 if c == '(' else -1
            if balance == -1:
                ans += 1
                balance += 1
        return ans + balance