class Solution:
    def minOperations(self, s: str) -> int:
        bit = '0'

        c1, c2 = 0, 0

        for ch in s:
            if ch != bit:
                c1 += 1
            if ch == bit:
                c2 += 1
            
            bit = '1' if bit == '0' else '0'
        
        return min(c1, c2)
