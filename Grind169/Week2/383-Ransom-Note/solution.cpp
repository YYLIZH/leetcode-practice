#include <string>
#include <unordered_map>

using namespace std;


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>map;

        for (int i =0;i<ransomNote.size();i++){
            if (map.find(ransomNote[i])==map.end()){
                map.insert(pair<char,int>(ransomNote[i],0));
            }
            else {
                map[ransomNote[i]]+=1;
            }
        }

        for (int j=0;j<magazine.size();j++){
            if (map.find(magazine[j])!=map.end()){
                map[magazine[j]]-=1;
            }
        }

        for(const auto&n:map){
            if (n.second>0){
                return false;
            }
        }

        return true;
    }
};