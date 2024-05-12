#include <iostream>
#include <limits.h>

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
    bool validate(TreeNode *root, long min, long max) {
        if(!root)
            return true;

        if(root->val >= max || root->val <= min)
            return false;
        return validate(root->left, min, root->val) && validate(root->right, root->val, max);
    }

    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }
};
 
int main() {
    TreeNode *root = new TreeNode(2); 
    root->left = new TreeNode(1); 
    root->right = new TreeNode(9); 

    Solution sol;
    std::cout<<sol.isValidBST(root);
    return 0;
}