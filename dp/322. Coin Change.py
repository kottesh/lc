from typing import List

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
         #@cache
         #def solver(amount):
         #    if amount == 0:
         #        return 0
         #    if amount < 0:
         #        return float('inf')

         #    mn = float('inf')
         #    for coin in coins:
         #        mn = min(mn, 1 + solver(amount - coin))
         #    
         #    return mn

         #ans = solver(amount)
         #return ans if ans != float('inf') else -1
        
        dp = [ float('inf') ] * (amount + 1) 
        dp[0] = 0

        for amt in range(1, amount + 1):
            for coin in coins:
                if (amt - coin) >= 0:
                    dp[amt] = min(dp[amt], 1 + dp[amt - coin])
        
        return dp[amount] if dp[amount] != float('inf') else -1

if __name__ == "__main__":
    print(Solution().coinChange([1, 2, 5], 11))
