from typing import List

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        if m == 0: 
            nums1[:] = nums2[:]
            return
        if n == 0:
            return

        i = j = 0

        temp = []
        while (i < m and j < n):
            if nums1[i] <= nums2[j]:
                temp.append(nums1[i])
                i += 1
            else:
                temp.append(nums2[j])
                j += 1

        if (i < m):
            temp.extend(nums1[i:m])
        if (j < n):
            temp.extend(nums2[j:n])

        nums1[:] = temp
        print(nums1)

        #Answer 2
        #nums1[:] = nums1[:m]
        #nums2[:] = nums2[:n]
        #nums1.extend(nums2)
        #nums1.sort()


if __name__ == "__main__":
    sol = Solution()        
    sol.merge([1,2,3,0,0,0], 3, [2,5,6], 3)
