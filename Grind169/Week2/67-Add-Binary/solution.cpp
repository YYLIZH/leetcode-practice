#include <string>
#include <math.h>

using namespace std;



class Solution {
public:
    string addBinary(string a, string b) {
        string ans;

        int carry=0;
        int i=a.size()-1;
        int j=b.size()-1;

        while (i>=0 || j>=0 || carry>=0) {
            if (i>=0) {
                carry+=(int)(a[i]);
                i--;
            }
            if (j>=0){
                carry+=(int)(b[j]);
                j--;
            }
            ans+=to_string(carry%2);
            carry/=2;
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};