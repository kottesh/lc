#include <bits/stdc++.h>

class Solution {
public:
    bool isPalindrome(std::string s) {
        std::string new_string;
        for(char c : s) {
            if(isalnum(c))
                new_string += tolower(c);
        } 

        std::cout << new_string << "\n"; 

        int low = 0,
            high = new_string.length() - 1;

        while(low <= high) {
            if(new_string[low] != new_string[high])
                return false;
            low++;
            high--;
        }

        return true;
    }
};

int main() {
}