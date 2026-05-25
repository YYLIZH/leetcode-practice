class Solution:
    def isValid(self, s: str) -> bool:
        mapping = {"}": "{", "]": "[", ")": "("}

        stack = []

        for c in s:
            if len(stack) == 0:
                stack.append(c)
            elif mapping.get(c, "") == stack[-1]:
                stack.pop()
            else:
                stack.append(c)

        return len(stack) == 0
