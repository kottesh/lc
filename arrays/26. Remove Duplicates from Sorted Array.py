from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        """
        have used two pointers
            left => for tracking current unique element in the array
            right => scans through the list
        """
        if not nums:
            return 0

        left = 1 

        for right in range(1, len(nums)):
            if nums[right-1] != nums[right]:
                nums[left] = nums[right]
                left += 1

        return left

if __name__ == "__main__":
    s = Solution()
    s.removeDuplicates([0,0,1,1,1,2,2,3,3,4])