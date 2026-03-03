#include <bits/stdc++.h>

using namespace std;

class Solution {
    bool isAlNum(const char& ch) {
        return ((ch >= 'a' and ch <= 'z') or (ch >= 'A' and ch <= 'Z') or (ch >= '0' and ch <= '9'));
    }
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;

        while (i <= j) {
            while (i < j and !isAlNum(s[i])) i++;
            while (i < j and !isAlNum(s[j])) j--;

            if (tolower(s[i]) != tolower(s[j]))
                return false;

            i++;
            j--;
        }

        return true;
    }
};

int main() {
    cout << (new Solution())->isPalindrome("0P");
}
