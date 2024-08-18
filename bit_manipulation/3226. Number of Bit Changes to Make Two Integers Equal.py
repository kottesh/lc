#class Solution:
#    def minChanges(self, n: int, k: int) -> int:
#        return bin(n^k).count('1') if n&k == k else -1

class Solution:
    def minChanges(self, n: int, k: int) -> int:
        if (n & k) != k: return -1
            
        cnt = 0

        for bit in bin(n)[2:]:
            cnt += int(bit)

        for bit in bin(k)[2:]:
            cnt -= int(bit)

        return cnt
