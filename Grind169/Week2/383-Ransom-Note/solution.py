from collections import defaultdict

class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        mapping=defaultdict(int)

        for i in ransomNote:
            mapping[i]+=1

        for j in magazine:
            mapping[j]-=1

        for key,value in mapping.items():
            if value>0:
                return False
            
        return True