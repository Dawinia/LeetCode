class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        l, r, count, ans, size = 0, -1, 0, 0, len(nums)
        while r + 1 < size:
            while r + 1 < size and count < k:
                r += 1
                count += nums[r] & 1
            if r >= size:
                break
            k_count_right_begin = r
            while r + 1 < size and not nums[r + 1] & 1:
                r += 1
            while l <= r and count == k:
                ans += r - k_count_right_begin + 1
                count -= nums[l] & 1
                l += 1
        return ans