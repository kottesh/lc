#include <bits/stdc++.h>

class Solution {
public:
    int evalRPN(const std::vector<std::string>& tokens) {
        std::stack<int> s;

        for (const auto & symbol : tokens) {
            if (!(symbol == "+" or symbol == "-" or symbol == "*" or symbol == "/"))
                s.push(std::stoi(symbol));
            else {
                int s_2 = s.top(); s.pop();
                int s_1 = s.top(); s.pop();

                if (symbol == "+")
                    s.push(s_1 + s_2);
                else if (symbol == "-")
                    s.push(s_1 - s_2);
                else if (symbol == "*")
                    s.push(s_1 * s_2);
                else if (symbol == "/")
                    s.push(s_1 / s_2);
            }
        }
        return s.top();
    }
};

int main() {
    std::cout << (new Solution())->evalRPN(std::vector<std::string> {"10","6","9","3","+","-11","*","/","*","17","+","5","+"});
}
