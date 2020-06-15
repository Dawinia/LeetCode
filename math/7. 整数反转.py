class Solution:
    def reverse(self, x: int) -> int:
        if abs(x) < 10:
            return x
        neg = x < 0
        ans, x, int_max = 0, abs(x), (1 << 32 - 1) // 10
        while x != 0:
            digit = x % 10
            x //= 10
            if ans > int_max or (ans == int_max and digit > 7): return 0
            if ans > int_max or (ans == int_max and digit < -8): return 0
            ans *= 10
            ans += digit

        return -ans if neg else ans