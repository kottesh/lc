#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <tuple>
#include <vector>

class Solution {
private:
    std::vector<int> primes;
    void genereatePrimes(int mx) {
        // sieve of eratosthenes
        std::vector<bool> prime(mx+1, true);
        for (int i = 2; i < sqrt(mx); i++) {
            if (prime[i]) {
                int j = pow(i, 2);
                while (j <= mx) {
                    prime[j] = false;
                    j += i;
                }
            }
        }

       for (int i = 2; i < mx+1; i++) {
           if (prime[i]) {
               primes.push_back(i);
           }
       }
    }
public:
    bool primeSubOperation(std::vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(0); std::cout.tie(0);

        int mx = *std::max_element(nums.begin(), nums.end());
        genereatePrimes(mx);

        for (int i = 0; i < nums.size(); i++) {
            int diff = (i == 0) ? nums[i] - 1 : nums[i] - nums[i-1] - 1;
            int lower = std::lower_bound(primes.begin(), primes.end(), diff) - primes.begin();

            if (lower == primes.size() or primes[lower] > diff) lower--; // for primes[lower] > diff workout this example {5, 8, 3}
            if (lower < 0) {
                if (i == 0 or nums[i] > nums[i-1]) continue;
                else return false;
            }
            nums[i] -= primes[lower];
        }
        return true;
    }
};

int main() {
    std::vector<int> nums {5, 8, 3};
    (new Solution())->primeSubOperation(
        nums
    );
}
