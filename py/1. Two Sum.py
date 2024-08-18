from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        visited = {} 

        for idx, num in enumerate(nums):
            diff = target - num;    
            if diff in visited: return [idx, visited[diff]]
            visited[num] = idx

        return []