class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t): return False

        s_map, t_map = {}, {}

        for char in s:
            if char not in s_map:
                s_map[char] = 1
            else:
                s_map[char] += 1

        for char in t:
            if char not in t_map:
                t_map[char] = 1
            else:
                t_map[char] += 1

        return True if s_map == t_map else False


        #for char in s_map:
        #    if s_map[char] != t_map.get(char, 0):
        #        return False
       
        #return True 