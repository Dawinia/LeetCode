class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0 or (x % 10 == 0 and x != 0): return False

        rx = 0
        while x > rx:
            rx = rx * 10 + x % 10
            x //= 10
        return rx == x or x == rx // 10