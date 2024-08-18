#include <bits/stdc++.h>

class Solution {
public:
    int reverse(int x) {
        int temp = abs(x); 
            
        long rev = 0;
        while (temp != 0) {
            rev = rev * 10 + (temp % 10); 
            temp /= 10;
        }

        if (x < 0) rev *= -1;

        if (!((rev >= INT_MIN) && (rev <= INT_MAX))) return 0;

        return rev;
    }
};

int main() {
    std::cout << (new Solution())->reverse(1234) << "\n";
}
