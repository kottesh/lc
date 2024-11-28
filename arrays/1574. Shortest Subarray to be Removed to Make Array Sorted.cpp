#include <bits/stdc++.h>

class Solution {
private:
    std::stack<int> store;
public:
    int findLengthOfShortestSubarray(const std::vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (i == 0 and arr[i] <= arr[i+1]) {
                store.push(arr[i]);
            } else if (i == n - 1 and arr[i] >= arr[i-1]) {
                store.push(arr[i]);
            } else if (arr[i] >= arr[i-1] and arr[i] <= arr[i+1]) {
                store.push(arr[i]);
            }
        }

        int stk_s = store.size();
        while (!store.empty()) store.pop();
        return stk_s == 0 ? n - 1 : n - stk_s;
    }
};

int main() {
    std::cout << (new Solution())->findLengthOfShortestSubarray(std::vector<int> {1,2,3,10,6,7,7});
}
