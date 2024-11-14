#include <bits/stdc++.h>

class Solution {
private:
    int remove_sub_str(std::string &s, const std::string &substr, int score) {
        std::stack<char> chars;
        int res = 0; 

        for (char ch : s) {
            if (!chars.empty() && chars.top() == substr[0] && ch == substr[1]) {
                res += score;
                chars.pop(); 
            }
            else
                chars.push(ch);
        }

        std::string temp = "";

        while (!chars.empty()) {
            temp += chars.top();
            chars.pop();
        }

        std::reverse(temp.begin(), temp.end());
        s = temp; 

        return res;
    }

public:
    int maximumGain(std::string s, int x, int y) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(0); std::cout.tie(0);

        int gain = 0;
        
        if (x > y) {
            gain += remove_sub_str(s, "ab", x); 
            gain += remove_sub_str(s, "ba", y); 
        } else {
            gain += remove_sub_str(s, "ba", y); 
            gain += remove_sub_str(s, "ab", x); 
        }

        return gain;
    }

    //int maximumGain(std::string s, int x, int y) {
    //std::ios_base::sync_with_stdio(false);
    //std::cin.tie(0); std::cout.tie(0);
    //    std::string f_str, s_str;
    //    int f_val, s_val;

    //    if (x > y) {
    //        f_str = "ab"; s_str = "ba";
    //        f_val = x; s_val = y;
    //    } else {
    //        f_str = "ba"; s_str = "ab";
    //        f_val = y; s_val = x;
    //    }

    //    int found;

    //    int ans = 0;
    //    int idx;
    //    do {
    //        if ((idx = s.rfind(f_str)) != std::string::npos) {
    //            found = 1;
    //            ans += f_val;
    //            s.erase(idx, 2);
    //        } else {
    //            found = 0;
    //        }
    //    } while (found);

    //    do {
    //        int idx;
    //        if ((idx = s.rfind(s_str)) != std::string::npos) {
    //            found = 1;
    //            ans += s_val;
    //            s.erase(idx, 2);
    //        } else {
    //            found = 0;
    //        }
    //    } while(found);

    //    return ans;
    //}
};

int main() {
    std::cout << (new Solution())->maximumGain("aabbaaxybbaabb", 5, 4) << "\n";
}

