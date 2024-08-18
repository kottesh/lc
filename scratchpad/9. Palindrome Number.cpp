#include <bits/stdc++.h>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int temp = x;       
            
        long rev = 0;
        while (temp != 0) {
            rev = (rev * 10) + temp % 10;
            temp /= 10;
        }

        return x == rev;
    }
};

int main() {
    std::cout<< (new Solution())->isPalindrome(22) << "\n";
}
