#include <unordered_map>
#include <string>

using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, bool> map;
        int res = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (map.find(s[i]) == map.end() || map[s[i]] == false)
            {
                map[s[i]] = true;
            }
            else
            {
                map[s[i]] = false;
                res += 2;
            }
        }

        for (auto &n : map)
        {
            if (n.second == true)
            {
                return res + 1;
            }
        }

        return res;
    }
};