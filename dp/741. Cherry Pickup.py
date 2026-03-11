from functools import cache
from typing import List

class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        n = len(grid)

        @cache
        def solver(i1, j1, i2, j2):
            if j1 < 0 or j1 >= n or j2 < 0 or j2 >= n or i1 >= n or i2 >= n:
                return -1e9

            if grid[i1][j1] == -1 or grid[i2][j2] == -1:
                return -1e9
            
            if i1 == n - 1 and j1 == n - 1:
                return grid[i1][j1]
            
            mx = -1e9 
            mx = max(
                mx,
                solver(i1, j1 + 1, i2, j2 + 1),
                solver(i1, j1 + 1, i2 + 1, j2),
                solver(i1 + 1, j1, i2 + 1, j2),
                solver(i1 + 1, j1, i2, j2 + 1),
            )

            if i1 == i2 and j1 == j2:
                return grid[i1][j1] + mx
            else:
                return grid[i1][j1] + grid[i2][j2] + mx

        return max(0, solver(0, 0, 0, 0))

if __name__ == "__main__":
    print(Solution().cherryPickup([[0,1,-1],[1,0,-1],[1,1,1]]))
    print(Solution().cherryPickup([[1,1,-1],[1,-1,1],[-1,1,1]]))
