from typing import List

class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        # ans = nums[0]

        # for num in nums[1:]:
        #     ans ^= num
        
        # return ans

        n = len(nums)
        l, r = 0, n - 1

        while l <= r:
            print(f"S: {l}, {r}")
            mid = (l + r) // 2 
            if (
                (mid == 0 or nums[mid] != nums[mid - 1]) and
                (mid == n - 1 or nums[mid] != nums[mid + 1])
            ):
                return nums[mid]
            elif nums[mid] == nums[mid - 1]:
                r = mid - 2
            else:
                l = mid + 2
            print(f"E: {l}, {r}")
        

if __name__ == "__main__":
    print(Solution().singleNonDuplicate([1,1,2,3,3,4,4,8,8]))
