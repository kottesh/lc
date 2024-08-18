from typing import List

class Solution:
    def canAliceWin(self, nums: List[int]) -> bool:
        self.sum_single = 0
        self.sum_double = 0
        for num in nums: 
            if num in range(10): 
                self.sum_single += num
            else:
                self.sum_double += num

        return True if self.sum_single != self.sum_double else False 
