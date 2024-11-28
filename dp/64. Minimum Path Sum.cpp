#include <bits/stdc++.h>

class Solution {
private:
    int findMin(
        const std::vector<std::vector<int>>&grid,
        int m, int n,
        std::vector<std::vector<int>> &dp
    ) {
        if (m == grid.size() - 1 and n == grid[0].size() - 1) return grid[m][n];
        if (m > grid.size() - 1 or n > grid[0].size() - 1) return INT_MAX;

        if (dp[m][n] != -1)
            return dp[m][n];

        return dp[m][n] = grid[m][n] + std::min(
            findMin(grid, m+1, n, dp), findMin(grid, m, n+1, dp)
        );
    }
public:
    int minPathSum(const std::vector<std::vector<int>>& grid) {
        std::vector<std::vector<int>> dp(grid.size(), std::vector<int>(grid[0].size(), -1));
        return findMin(grid, 0, 0, dp);
    }
};

int main() {
    std::cout << (new Solution())->minPathSum(std::vector<std::vector<int>> {{1,3,1},{1,5,1},{4,2,1}});
}
