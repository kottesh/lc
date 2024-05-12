#include <bits/stdc++.h>

class Solution {
public:
    // time limit exceeded in the below code on the 669th testcase 

    // long long maximumHappinessSum(std::vector<int>& happiness, int k) {
    //     long long res = 0;  

    //     std::vector<int>::iterator max;
    //     for (int i = 0; i < k; i++) {
    //         max = std::max_element(happiness.begin(), happiness.end());
    //         res += *max;
    //         happiness.erase(max);
    //         if (!happiness.empty())
    //             std::transform(happiness.begin(), happiness.end(), happiness.begin(), [](int &x) {return (x <= 0) ? 0 : x - 1;});
    //     }

    //     return res;
    // }

    long long maximumHappinessSum(std::vector<int>& happiness, int k) {
        long long res = 0;
        std::sort(happiness.begin(), happiness.end(), [](int x, int y){return x > y;});

        for (int i = 0; i < k; i++) {
            if ((happiness[i] - i) > 0) {
                res += happiness[i] - i;
            }
        }

        return res;
    }
};

int main() {
    std::vector<int> happiness {12,1,42};

    std::cout << (new Solution())->maximumHappinessSum(happiness, 3) << std::endl;
    return 0;
}