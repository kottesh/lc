#include <bits/stdc++.h>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());
        
        std::vector<std::vector<int>> res;
           
        res.push_back(intervals[0]);
        for (auto interval = intervals.begin() + 1 ; interval != intervals.end(); interval++) {
            if (res.back()[1] >= (*interval)[0])
                res.back()[1] = std::max(res.back()[1], (*interval)[1]);
            else
                res.push_back((*interval));
        }

        return res;
    }
};

int main() {
    std::vector<std::vector<int>> a {{1,6},{2,3},{8,10},{15,18}};
    std::vector<std::vector<int>> ans = (new Solution)->merge(a); 

    for (auto& ele : ans) {
        std::cout << ele[0] << ", " << ele[1] << std::endl;
    }
}
