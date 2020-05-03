class Solution:
    def isHappy(self, n: int) -> bool:
        def get_num(n):
            ans = 0
            while n > 0:
                d = n % 10
                ans += d * d
                n //= 10
            return ans
        slow = fast = n
        slow = get_num(slow)
        fast = get_num(fast)
        fast = get_num(fast)
        while slow != fast:
            slow = get_num(slow)
            fast = get_num(fast)
            fast = get_num(fast)
            if fast == 1:
                return True
        return slow == 1