#include <bits/stdc++.h>

class Solution {
public:
    int maxScore(const std::vector<int>& cardPoints, int k) {
        int lsum = 0, rsum = 0, sum = 0; 

        for (int i = 0; i < k; i++)
            lsum += cardPoints[i];

        sum = lsum;

        int ridx = cardPoints.size() - 1;

        for (int i = k - 1; i >= 0; i--) {
            lsum -= cardPoints[i];
            rsum += cardPoints[ridx--];
            sum = std::max(sum, lsum + rsum);
        }

        return sum;
    }
};

int main () {
    std::cout << (new Solution())->maxScore(std::vector<int> {1,2,3,4,5,6,1}, 3); 
}
