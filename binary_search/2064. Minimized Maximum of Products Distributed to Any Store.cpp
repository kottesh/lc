#include <bits/stdc++.h>

class Solution {
private:
    bool canDistribute(const int &k, const int &n, std::vector<int> quantities) {
        int count = 0;
        // for (int &qty : quantities) {
        //     while (qty) {
        //         if (qty >= k)
        //             qty -= k;
        //         else if (qty < k)
        //             qty -= qty;
        //         count++;
        //     }
        // }

        for (int & qty : quantities) {
            count += (qty + k -1) / k;
        }
        return count <= n;
    }
public:
    int minimizedMaximum(int n, std::vector<int>& quantities) {
        int max = *std::max_element(quantities.begin(), quantities.end());

        if (n == quantities.size()) return max;

        // linear search
        // for (int i = 1 ; i < max ; i++) {
        //     if (canDistribute(i, n, quantities)) return i;
        // }
        int left = 1, right = max;

        // binary search
        while (left <= right) {
            int mid = (left + right) / 2;

            if (canDistribute(mid, n, quantities)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};

int main() {
    std::vector<int> quantities {15, 10, 10};
    std::cout << (new Solution())->minimizedMaximum(7, quantities);
}
