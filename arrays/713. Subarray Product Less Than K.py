"""
class Solution:
    count: int = 0
    def product(self, nums: list[int]) -> int:
        val = 1
        for num in nums:
            val *= num
        return val

    def numSubarrayProductLessThanK(self, nums: list[int], k: int) -> int:
        for i in range(1, len(nums)+1):
            j = 0;
            while i + j != len(nums) + 1:
                print(nums[j:i+1])
                if self.product(nums[j:i]) < k:
                    self.count += 1
                j += 1
        return self.count
                
if __name__ == "__main__":
    sol = Solution()
    print(sol.numSubarrayProductLessThanK([10,9,10,4,3,8,3,3,6,2,10,10,9,3], 19))
"""

class Solution:
    def numSubarrayProductLessThanK(self, nums: list[int], k: int) -> int:
        cnt = 0

        for w_size in range(1, len(nums)+1):
            w_prod = 1
            start = 0
            end = 0

            while (end < w_size):
                w_prod *= nums[end]
                end += 1

            while True:
                if (w_prod < k):
                    cnt += 1

                if (end == len(nums)):
                    break

                w_prod //= nums[start]
                w_prod *= nums[end]
                start += 1
                end += 1

        return cnt    

sol = Solution()
print(sol.numSubarrayProductLessThanK([10,5,2,6], 100))