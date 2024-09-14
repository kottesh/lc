#include <bits/stdc++.h>
    
class Solution {
public:
    int hIndex(const std::vector<int>& citations) {
        int h;
        int j;
        for (h = 1; h < citations.size(); h++) {
            int _papers = 0;
            for (int j = 0; j < citations.size(); j++) {
                if (citations[j] > h) ++_papers; 
                else if (citations[j] == h) break;
            } 
            if (j == citations.size()) break;
        }
        return h;
    }
};

int main() {
    std::cout << (new Solution())->hIndex(std::vector<int> {3,0,6,1,5});
    return 0;
}
