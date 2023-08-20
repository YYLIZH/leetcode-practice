class Solution:
    def longestPalindrome(self, s: str) -> int:
        res = 0
        map = {}

        for ch in s:
            if map.get(ch) is None:
                map[ch] = 1
            else:
                map.pop(ch)
                res += 2

        if map:
            res += 1

        return res
