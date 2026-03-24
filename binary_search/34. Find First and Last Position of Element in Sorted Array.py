from typing import List

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        def binSearch(searchRight: bool):
            idx = -1
            l, r = 0, len(nums) - 1
            while l <= r:
                mid = (r + l) // 2
                if nums[mid] == target:
                    idx = mid
                    if searchRight:
                        l = mid + 1
                    else:
                        r = mid - 1
                elif nums[mid] < target:
                    l = mid + 1
                else:
                    r = mid - 1

            return idx

        return [binSearch(False), binSearch(True)]

if __name__ == "__main__":
    print(Solution().searchRange([5,7,7,8,8,10], 8))
