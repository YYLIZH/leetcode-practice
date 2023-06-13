# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

def isBadVersion(version:int)->bool:
    pass

class Solution:
    def firstBadVersion(self, n: int) -> int:
        # apply binary search
        low=1
        high=n

        if isBadVersion(1) is True:
            return 1
        
        
        while low<=high:
            middle=low+(high-low)//2

            if isBadVersion(middle) is True:
                high=middle-1
            else:
                low=middle+1
        return low