class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        if not nums1 or not nums2: return []
        m = {nums2[0]: -1}
        s, ans = [nums2[0]], []
        for i in range(1, len(nums2)):
            m[nums2[i]] = -1
            while len(s) and nums2[i] > s[-1]:
                m[s[-1]] = nums2[i]
                s.pop(-1)
            s.append(nums2[i])
        for i in nums1:
            ans.append(m[i])
        return ans
