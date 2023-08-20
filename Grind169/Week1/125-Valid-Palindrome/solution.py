class Solution:
    def isPalindrome(self, s: str) -> bool:
        # use two pointer
        left = 0
        right = len(s) - 1

        while left <= right:
            if not s[left].isalnum():
                left += 1
                continue
            if not s[right].isalnum():
                right -= 1
                continue

            l_char = s[left].lower()
            r_char = s[right].lower()

            if l_char == r_char:
                left += 1
                right -= 1
            else:
                return False

        return True
