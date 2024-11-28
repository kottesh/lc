#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> dailyTemperatures(const std::vector<int>& temperatures) {
        std::vector<int> res(temperatures.size(), 0);
        std::stack<int> s;
        
        for (int i = 0; i < temperatures.size(); i++) {
            while (!s.empty() and temperatures[i] > temperatures[s.top()]) {
                int idx = s.top();
                res[idx] = i - idx; 
                s.pop();
            }
            s.push(i);
        }
        
        return res;
    }
};

int main() {
    std::vector<int> days = (new Solution())->dailyTemperatures(std::vector<int> {73, 74, 75, 71, 69, 72, 76, 73});

    for (auto day : days) 
        std::cout << day << ", ";
}

