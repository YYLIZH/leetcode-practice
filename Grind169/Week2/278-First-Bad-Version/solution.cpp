bool isBadVersion(int n);

class Solution {
public:
    int firstBadVersion(int n) {
        // apply binary search
        int low=1;
        int high=n;

        while (low<=high) {
            int middle=low+(high-low)/2;

            if (isBadVersion(middle)==true) {
                high=middle-1;
            }
            else {
                low=middle+1;
            }
        }

        return low;
    }
};