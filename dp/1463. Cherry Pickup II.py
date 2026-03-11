from typing import List
from functools import cache

class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        
        @cache
        def solver(i, j1, j2):
            if j1 < 0 or j2 < 0 or j1 >= n or j2 >= n:
                return -1e9 

            if i == m - 1:
                if j1 == j2:
                    return grid[i][j1]
                return grid[i][j1] + grid[i][j2]
            
            mx = 0 
            for dj1 in range(-1, 2): # for robot 1
                for dj2 in range(-1, 2): # for robot 2
                    lcherries = solver(i + 1, j1 + dj1, j2 + dj2)

                    if j1 == j2:
                        mx = max(mx, grid[i][j1] + lcherries)
                    else:
                        mx = max(mx, grid[i][j1] + grid[i][j2] + lcherries)

            return mx

        return solver(0, 0, n - 1)

        # tabulation
        
        # dp = [[[None] * n for _ in range(n)] for _ in range(m)]
        # 
        # for j1 in range(n):
        #     for j2 in range(n):
        #         dp[m - 1][j1][j2] = (
        #             grid[m - 1][j1] 
        #             if j1 == j2 
        #             else grid[m - 1][j1] + grid[m - 1][j2]
        #         )
        # 
        # for i in range(m - 2, -1, -1):
        #     for j1 in range(n):
        #         for j2 in range(n):
        #             mx = 0
        #             for dj1 in range(-1, 2): # for robot 1
        #                 for dj2 in range(-1, 2): # for robot 2
        #                     lcherries = (
        #                         -1e9
        #                         if j1 + dj1 < 0 or j1 + dj1 >= n or j2 + dj2 < 0 or j2 + dj2 >= n 
        #                         else dp[i + 1][j1 + dj1][j2 + dj2]
        #                     )

        #                     if j1 == j2:
        #                         mx = max(mx, grid[i][j1] + lcherries)
        #                     else:
        #                         mx = max(mx, grid[i][j1] + grid[i][j2] + lcherries)
        #     
        #             dp[i][j1][j2] = mx

        # return dp[0][0][n - 1]

if __name__ == "__main__":
    print(Solution().cherryPickup([[3,1,1],[2,5,1],[1,5,5],[2,1,1]]))
    print(Solution().cherryPickup([[1,0,0,0,0,0,1],[2,0,0,0,0,3,0],[2,0,9,0,0,0,0],[0,3,0,5,4,0,0],[1,0,2,3,0,0,6]]))
