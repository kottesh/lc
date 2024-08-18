from typing import List

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        # Bruteforce approach
        res = "" 

        min_len = float('inf')
        for str in strs:
            min_len = min(min_len, len(str))

        arb_str = strs[0]
        for i in range(min_len):
            for str in strs:
                if str[i] != arb_str[i]:
                    return res 
            res += str[i]
        
        return res


if __name__ == "__main__":
    print(Solution().longestCommonPrefix( ["flower","flow","flight"]))
