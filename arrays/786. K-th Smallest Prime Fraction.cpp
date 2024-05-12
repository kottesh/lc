#include <bits/stdc++.h>

class Solution {
    std::priority_queue<std::pair<double, std::pair<int, int>>, std::vector<std::pair<double, std::pair<int, int>>>, std::greater<>> minHeap;
public:
    std::vector<int> kthSmallestPrimeFraction(std::vector<int>& arr, int k) {
        int N = arr.size();
        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                minHeap.push(std::make_pair((double)arr[i] / arr[j], std::make_pair(arr[i], arr[j])));
            }
        } 


        for (int cnt = 0; cnt < k-1; cnt++) {
            minHeap.pop();
        }

        auto res = minHeap.top();
        return {res.second.first, res.second.second};
    }
};

int main() {
    std::vector<int> vals {1,2,3,5};
    std::vector<int> res = (new Solution())->kthSmallestPrimeFraction(vals, 3);

    for (int val : res) {
        std::cout << val << " ";
    }
    return 0;
}