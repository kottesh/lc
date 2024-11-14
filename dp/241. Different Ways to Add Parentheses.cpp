class Solution {
public:
    std::vector<int> diffWaysToCompute(std::string expression) {
        if (expression.length() == 1) {
            return {stoi(expression)};
        }

        for (int i = 0; i < expression.length(); i++) {
            if (expression[i] == '-' || expression[i] == '*' || expression[i] == '+') {

            }
        } 
    }
};
