# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        if not nums: return None

        def create(left, right):
            if left > right:
                return None
            
            mid = left + (right - left) // 2
            head = TreeNode(nums[mid])
            head.left = create(left, mid - 1)
            head.right = create(mid + 1, right)
            return head

        return create(0, len(nums) - 1)