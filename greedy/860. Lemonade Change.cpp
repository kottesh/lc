#include <bits/stdc++.h>

class Solution {
public:
    bool lemonadeChange(const std::vector<int>& bills) {
        int cnt_5 = 0, cnt_10 = 0; 

        for (const int &bill : bills) {
            if (bill == 5)
                cnt_5++;
            else if (bill == 10) {
                if (cnt_5) {
                    cnt_5--;
                    cnt_10++;
                } else return false;
            } else {
                if (cnt_5 and cnt_10) {
                    cnt_5--; cnt_10--;
                } else if (cnt_5 >= 3) {
                    cnt_5 -= 3;
                } else return false;
            }
        }

        return true;
    }
};

int main() {
    std::cout << (new Solution())->lemonadeChange(std::vector<int> {5, 5, 5, 10, 20});
}
