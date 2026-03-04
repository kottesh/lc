from typing import List

class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        ans = 0 

        def ok(x, y) -> bool:
            for i in range(len(mat)):
                if i != x and mat[i][y] == 1:
                    return False
            for i in range(len(mat[0])):
                if i != y and mat[x][i] == 1:
                    return False
            return True

        for i in range(len(mat)):
            for j in range(len(mat[0])):
                if mat[i][j] == 1 and ok(i, j):
                    ans += 1 

        return ans

if __name__ == "__main__":
    print(Solution().numSpecial([[1,0,0],[0,0,1],[1,0,0]]))
    print(Solution().numSpecial([[1,0,0],[0,1,0],[0,0,1]]))

