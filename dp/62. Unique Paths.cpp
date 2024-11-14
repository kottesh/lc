class Solution {
private:
    int compute_paths(int i, int j, const int m, const int n, std::vector<std::vector<int>>& dp) {
        if (i == m - 1 && j == n - 1)
            return 1;
        if (i > m-1 || j > n-1)
            return 0;
        if (dp[i][j] > 0)
            return dp[i][j];

        return dp[i][j] = compute_paths(i+1, j, m, n, dp) + compute_paths(i, j+1, m, n, dp);
    }
public:
    int uniquePaths(int m, int n) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(0); std::cout.tie(0);
        
        std::vector<std::vector<int>> dp (m, std::vector<int>(n));
        return compute_paths(0, 0, m, n, dp);
    }
};
