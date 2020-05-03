class Solution:
    def minArray(self, numbers: List[int]) -> int:
        size = len(numbers)
        if size < 1:
            return -1
        left, right = 0, size - 1
        while left < right:
            mid = left + ((right - left) >> 1)
            if numbers[mid] > numbers[right]:
                left = mid + 1
            elif numbers[mid] < numbers[right]:
                right = mid
            else:
                right -= 1
        return numbers[right]

