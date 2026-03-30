from typing import List

class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        Lmx = [ 0 ] * n
        Rmx = [ 0 ] * n
        ans = 0

        for i in range(n):
            if i == 0:
                Lmx[i] = height[i]
                Rmx[n - i - 1] = height[n - i - 1]
            else:
                Lmx[i] = max(Lmx[i - 1], height[i])
                Rmx[n - i - 1] = max(Rmx[n - i], height[n - i - 1])

        for idx in range(len(height)):
            ans += min(Lmx[idx], Rmx[idx]) - height[idx]

        return ans

if __name__ == "__main__":
    print(Solution().trap([0,1,0,2,1,0,1,3,2,1,2,1])) 
    print(Solution().trap([4,2,0,3,2,5])) 
