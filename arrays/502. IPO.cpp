#include <bits/stdc++.h>

void print (const std::vector<int>& vec) {
    for (auto val : vec) {
        std::cout << val << std::endl; 
    } 
    return;
}

class Solution {
public:
    int findMaximizedCapital(int k, int w, std::vector<int>& profits, std::vector<int>& capital) {
        std::priority_queue<int> max_heap; // this max_heap contains the affordable project with high profit in the root.
        int len = capital.size();

        std::vector<std::pair<int, int>> works;
        for (int i = 0; i < len; i++) {
            works.emplace_back(std::make_pair(capital[i], profits[i]));
        }
        std::sort(works.begin(), works.end());

        //for (int j = 0; j < capital.size() - 1; j++) {
        //    for (int i = 0; i < capital.size() - j - 1; i++) {
        //        if (capital[i] > capital[i+1]) {
        //            std::swap(capital[i], capital[i+1]);
        //            std::swap(profits[i], profits[i+1]);
        //        }
        //    }
        //}
        
        int idx = 0;
        while (k) {
            while(idx < len && works[idx].first <= w) {
                max_heap.push(works[idx].second);
                idx++;
            }
            if (max_heap.empty()) break;
            
            w += max_heap.top();
            max_heap.pop();
            k--;
        }

        return w;
    }
};

// bruteforce shit (tle)
//class Solution {
//public:
//    int findMaximizedCapital(int k, int w, std::vector<int>& profits, std::vector<int>& capital) {
//        int prev = -1, profit = 0;
//        while (k && !profits.empty()) {
//            for (int i = 0; i < profits.size(); i++) {
//                if (w >= capital[i]) {
//                    if (prev == -1) {
//                        profit = profits[i];
//                        prev = i;
//                    } else {
//                        if (profits[prev] < profits[i]) {
//                            prev = i;
//                            profit = profits[i];
//                        }
//                    }
//                }
//            }
//            if (profit == 0) break; // didn't find one with the current captial 
//            w += profit;
//            profit = 0;
//            profits.erase(profits.begin() + prev); capital.erase(capital.begin() + prev);
//            prev = -1;
//            k--;
//        }      
//
//        return w;
//    }
//};

int main() {
    std::vector<int> a = {1, 2, 3};
    std::vector<int> b = {1, 2, 0};
    std::cout << (new Solution)->findMaximizedCapital(3, 0, a, b);
    return 0;
}
