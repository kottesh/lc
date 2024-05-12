#include <bits/stdc++.h>

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        int max_len = std::max(a.length(), b.length());

        std::reverse(a.begin(), a.end());    
        std::reverse(b.begin(), b.end());    

        std::string res;

        int carry = 0;
        for(int i = 0; i < max_len + 1; i++) {
            int x = (i > a.length() - 1) ? 0 : a[i] - '0'; 
            int y = (i > b.length() - 1) ? 0 : b[i] - '0'; 

            std::cout << x << " " << y << "\n";
            std::cout << ((x ^ y)) << "\n";

            if(i != max_len + 1) {
                res.push_back((x ^ y ^ carry));
            } else {
                if((x & y) != 0) {
                    res.push_back(carry);
                }
            }

            carry = ((x & y) != 0) ? 1 : 0;
        }

        std::reverse(res.begin(), res.end());
        return res; 
    }
};

int main() {
    Solution run;

    std::cout << run.addBinary("11", "1") << "\n";
} 
