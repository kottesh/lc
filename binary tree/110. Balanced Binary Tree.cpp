#include <iostream>
#include <algorithm>
#include <cmath>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int findHeight(TreeNode *root) {
        if(!root) return -1;
        return 1 + std::max(findHeight(root->left), findHeight(root->right));
    }

    bool isBalanced(TreeNode* root) {
        if(!root) {
            return true;
        }
        if(abs(findHeight(root->left) - findHeight(root->right)) > 1) return false;
        return true && isBalanced(root->left) && isBalanced(root->right);
    }
};

int main() {
    return 0;
}