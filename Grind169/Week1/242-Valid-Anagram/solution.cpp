#include <string>
#include <unordered_map>
using namespace std;


class Solution {
public:
    bool isAnagram(string s, string t) {
        // Use hashmap
        if (s.length()!=t.length()) return false;

        int n=s.length();

        unordered_map<char,int>map;

        for (int i=0;i<n;i++){
            map[s[i]]++;
            map[t[i]]--;
        }

        for (auto count:map){
            if (count.second) return false;
        }

        return true;
    }
};