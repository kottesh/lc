from typing import List

class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        # @cache
        # def solver(idx, target):
        #     if target == 0:
        #         return 1

        #     if idx < 0:
        #         return 0
        #     
        #     not_pick = solver(idx - 1, target)
        #     pick = 0
        #     if (target - coins[idx]) >= 0:
        #         pick = solver(idx, target - coins[idx])
        #     
        #     return not_pick + pick

        # return solver(len(coins) - 1, amount)

        dp = [[0] * (amount + 1) for _ in range(len(coins))]

        for idx in range(len(coins)):
            dp[idx][0] = 1

        for t in range(amount + 1):
            if t % coins[0] == 0:
                dp[0][t] = 1

        for idx in range(1, len(coins)):
            for target in range(1, amount + 1):
                not_pick = dp[idx - 1][target]
                pick = 0
                if (target - coins[idx]) >= 0:
                    pick = dp[idx][target - coins[idx]]

                dp[idx][target] = not_pick + pick

        return dp[len(coins) - 1][amount]


if __name__ == "__main__":
    print(Solution().change(5, [1, 2, 5]))
    print(Solution().change(2, [3]))
    print(Solution().change(10, [10]))
    print(Solution().change(10, [11]))
