from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        # use bfs
        queue = [root]

        while queue:
            node = queue.pop(0)
            tmp = node.left
            node.left = node.right
            node.right = tmp
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)

        return root
