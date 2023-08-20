class Solution:
    def addBinary(self, a: str, b: str) -> str:
        s = []
        hold = 0
        i = len(a) - 1
        j = len(b) - 1

        while i >= 0 or j >= 0 or hold:
            if i >= 0:
                hold += int(a[i])
                i -= 1
            if j >= 0:
                hold += int(b[j])
                j -= 1

            s.append(str(hold % 2))

            hold = hold // 2

        return "".join(reversed(s))
