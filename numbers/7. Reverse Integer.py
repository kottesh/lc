import math

class Solution:
    def rev(self, num: str) -> int:
        return int(num[::-1])

    def reverse(self, x: int) -> int:
        num = self.rev(str(x) if x > 0 else str(-x))
        num = -num if x < 0 else num

        return 0 if not (num < math.pow(2, 31) - 1 and num > math.pow(-2, 31)) else num