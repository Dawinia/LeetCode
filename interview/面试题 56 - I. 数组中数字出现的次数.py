class Solution:
    def singleNumbers(self, nums: List[int]) -> List[int]:
        ans, a, b = 0, 0, 0
        for num in nums:
            ans ^= num

        step = 1
        while ans & step == 0:
            step <<= 1
        for num in nums:
            if num & step:
                a ^= num
            else:
                b ^= num
        return [a, b]