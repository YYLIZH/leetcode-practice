from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


# DFS
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        def depth(node: Optional[TreeNode]):
            if not node:
                return 0

            return 1 + max(depth(node.left), depth(node.right))

        return depth(root)


# BFS
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        level = [root]
        depth = 0

        while level:
            queue = []
            for node in level:
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)

            level = queue
            depth += 1

        return depth
