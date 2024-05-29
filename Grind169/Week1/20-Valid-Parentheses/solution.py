class Solution:
    def isValid(self, s: str) -> bool:
        stack = [s[0]]
        mapping = {"}": "{", "]": "[", ")": "("}
        for el in s[1:]:
            if not stack:
                stack.append(el)
                continue
            if mapping.get(el) == stack[-1]:
                stack.pop()
            else:
                stack.append(el)

        return len(stack) == 0
