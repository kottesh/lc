class Solution {
    int compute_paths(
            int i, int j,
            const int m, const int n,
            auto &dp, const auto matrix
    ) {
        if (matrix[m-1][n-1] == 1 || i > m - 1 || j > n - 1 || matrix[i][j] == 1)
            return 0;
        if (i == m - 1 && j == n - 1)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];

        return dp[i][j] = compute_paths(i+1, j, m, n, dp, matrix) + compute_paths(i, j+1, m, n, dp, matrix);
    }
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(0); std::cout.tie(0);

        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        std::vector<std::vector<int>> dp (m, std::vector<int>(n, -1));
        return compute_paths(0, 0, m, n, dp, obstacleGrid);
    }
};
