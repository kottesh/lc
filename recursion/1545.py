from functools import cache

class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        def invert(s) -> str:
            return "".join(
                map(
                    lambda x: "0" if x == "1" else "1",
                    list(reversed(s))
                )
            )
        
        @cache
        def solver(n):
            if n == 0:
                return "0"
            return solver(n - 1) + "1" + invert(solver(n - 1)) 
        
        res = solver(n - 1)
        return res[k]

if __name__ == "__main__":
    print(Solution().findKthBit(3, 0))
