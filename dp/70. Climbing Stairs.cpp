#include <bits/stdc++.h>

// class Solution {
// private:
//     std::unordered_map<int, int> map;
//     int countWays(int n, int curr) {
//         if (curr == n) return 1;
//         if (curr > n ) return 0;
//         if (map.find(curr) != map.end()) return map[curr];

//         map[curr] = countWays(n, curr+1) + countWays(n, curr + 2);

//         return map[curr];
//     }
// public:
//     int climbStairs(int n) {
//         if (n == 0) return 0;
//         return countWays(n, 0);
//     }
// };

// class Solution {
// public:
//     int climbStairs(int n) {
//         int dp[n+1];
//         dp[0] = 1;
//         dp[1] = 1;

//         for (int i = 2; i <= n; i++)
//             dp[i] = dp[i-1] + dp[i-2];

//         return dp[n];
//     }
// };


// see the python code I have written.
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;

        int prev = 1, prevPrev = 1;

        int ans;
        for (int i = 2; i <= n; i++) {
            ans = prev + prevPrev;
            prevPrev = prev;
            prev = ans;
        }

        return ans;
    }
};

int main() {
    std::cout << (new Solution)->climbStairs(1);
}
