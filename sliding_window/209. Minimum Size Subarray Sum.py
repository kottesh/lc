from typing import List

class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        min_length = float('inf') 
        window_start = window_sum = 0

        for window_end in range(len(nums)):
            window_sum += nums[window_end]

            while (window_sum >= target):
                min_length = min(min_length, window_end - window_start + 1)
                window_sum -= nums[window_start]
                window_start += 1

        return 0 if min_length == float('inf') else min_length

sol = Solution()
print(sol.minSubArrayLen(7, [2,3,1,2,4,3]))
