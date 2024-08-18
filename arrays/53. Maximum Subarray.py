from typing import List

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        mx = float('-inf')
        i = j = 0
        sum = 0
        start = 0

        for idx, num in enumerate(nums):
            if sum == 0:
                start = idx 

            sum += num

            if sum > mx:
                i, j = start, idx + 1
                mx = sum
            sum = 0 if sum < 0 else sum

        print(nums[i:j])
        return mx if mx != 0 else 0

if __name__ == "__main__":
    s = Solution() 
    print(s.maxSubArray([-2,1,-3,4,-1,2,1,-5,4]))