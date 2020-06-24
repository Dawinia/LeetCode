class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        if not nums: return -1

        nums.sort()
        ans, size = sum(nums[:3]), len(nums)

        for i in range(size - 2):
            left, right = i + 1, size - 1
            while left < right:
                s = nums[i] + nums[left] + nums[right]
                ans = s if abs(ans - target) > abs(s - target) else ans

                if s == target:
                    return target
                elif s > target:
                    pr = right - 1
                    while pr > left and nums[pr] == nums[right]:
                        pr -= 1
                    right = pr
                else:
                    nl = left + 1
                    while nl < right and nums[nl] == nums[left]:
                        nl += 1
                    left = nl
        
        return ans


