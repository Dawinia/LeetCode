class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        if not nums1 or not nums2: return []
        l1, l2 = len(nums1), len(nums2)
        if l1 > l2:
            nums1, nums2 = nums2, nums1
        m, ans = defaultdict(int), []
        for n in nums1:
            m[n] += 1
        for n in nums2:
            if m[n] > 0:
                ans.append(n)
                m[n] -= 1
        return ans

#####################################################

class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        if not nums1 or not nums2: return []
        l1, l2 = len(nums1), len(nums2)

        nums1.sort()
        nums2.sort()

        i = j = 0
        ans = []
        while i < l1 and j < l2:
            while i < l1 and nums1[i] < nums2[j]:
                i += 1
            if i == l1:
                return ans
            while j < l2 and nums1[i] > nums2[j]:
                j += 1
            if j == l2:
                return ans
            if nums1[i] == nums2[j]:
                ans.append(nums1[i])
                i, j = i + 1, j + 1
        return ans