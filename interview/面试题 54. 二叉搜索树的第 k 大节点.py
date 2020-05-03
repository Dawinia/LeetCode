# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def kthLargest(self, root: TreeNode, k: int) -> int:
        nums = []
        def inorderSearch(root):
            if not root:
                return

            inorderSearch(root.left)
            if len(nums) == k:
                nums.pop(0)
            nums.append(root.val)
            inorderSearch(root.right)
            
        inorderSearch(root)
        
        return nums[0]


        