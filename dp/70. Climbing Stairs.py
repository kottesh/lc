# Refer Neetcode YT (https://www.youtube.com/watch?v=Y0lT9Fck7qI)

class Solution:
    def climbStairs(self, n: int) -> int:
        x, y = 1, 1

        for i in range(n-1):
            store = x
            x = x + y
            y = store
        return x
