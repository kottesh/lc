class Solution {
private:
    bool check_three_x_three(std::vector<std::vector<char>> &board, int y_start, int y_end, int x_start, int x_end) {
        std::unordered_set<char> seen;
        
        for (int i = y_start; i < y_end; i++) {
            for (int j = x_start; j < x_end; j++) {
                if (board[i][j] != '.' && seen.contains(board[i][j])) return false;
                seen.insert(board[i][j]);
            }
        }
        seen.clear();
        return true;
    }
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(0); std::cout.tie(0);

        std::unordered_set<char> seen;

        for (auto row : board) {
            seen.clear();
            for (char ch : row) {
                if (ch != '.' && seen.contains(ch))
                    return false;
                else
                    seen.insert(ch);
            }
        }     
        
        for (int i = 0; i < board.size(); i++) {
            seen.clear();
            for (auto row : board) {
                if (row[i] != '.' && seen.contains(row[i]))
                    return false; 
                else
                    seen.insert(row[i]);
            }
        }

        if (!check_three_x_three(board, 0, 3, 0, 3)) return false;
        if (!check_three_x_three(board, 0, 3, 3, 6)) return false;
        if (!check_three_x_three(board, 0, 3, 6, 9)) return false;
        
        if (!check_three_x_three(board, 3, 6, 0, 3)) return false;
        if (!check_three_x_three(board, 3, 6, 3, 6)) return false;
        if (!check_three_x_three(board, 3, 6, 6, 9)) return false;

        if (!check_three_x_three(board, 6, 9, 0, 3)) return false;
        if (!check_three_x_three(board, 6, 9, 3, 6)) return false;
        if (!check_three_x_three(board, 6, 9, 6, 9)) return false;
        return true;
    }
};

