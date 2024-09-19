struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

typedef ListNode* Node;

class Solution {
public:
    std::vector<std::vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(0); std::cout.tie(0);

        std::vector<std::vector<int>> matrix(m, std::vector(n, -1));
        if (!head) return matrix;

        int left = 0, top = 0, right = n - 1, bottom = m - 1;

        while (left <= right && top <= bottom) {
            for (int col = left; col <= right && head; col++) {
                matrix[top][col] = head->val;
                head = head->next;
            } 
            top++;

            for (int row = top; row <= bottom && head; row++) {
                matrix[row][right] = head->val;
                head = head->next;
            }
            right--;
            
            for (int col = right; col >= left && head; col--) {
                matrix[bottom][col] = head->val;
                head = head->next;
            }
            bottom--;
            
            for (int row = bottom; row >= top && head; row--) {
                matrix[row][left] = head->val;
                head = head->next;
            }
            left++;
        }

        return matrix;
    }
};

