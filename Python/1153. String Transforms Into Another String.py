class Solution:
    def canConvert(self, str1: str, str2: str) -> bool:
        if str1 == str2:
            return True
        con_map = dict()
        for i in range(len(str1)):
            if str1[i] not in con_map:
                con_map[str1[i]] = str2[i]
            elif con_map[str1[i]] != str2[i]:
                return False
        return len(set(str2)) < 26
                
