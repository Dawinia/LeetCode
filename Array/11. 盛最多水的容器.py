class Solution:
    def maxArea(self, height: List[int]) -> int:
        size = len(height)
        if size == 2:
            return min(height[1], height[0])
        left, right = 0, size - 1
        ans = 0
        while left < right:
            lh, rh = height[left], height[right]
            if lh < rh:
                ans = max(ans, lh * (right - left))
                left += 1
            else:
                ans = max(ans, rh * (right - left))
                right -= 1
        return ans