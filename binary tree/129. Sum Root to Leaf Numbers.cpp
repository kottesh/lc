#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

typedef TreeNode node;
 
class Solution {
private:
    // this is a recursive approach. I'll do a preorder traversal and find the value.

    // ! -> nullptr. If I use the !, then negation will get to true. just think in opposite way.
    int findSum(node* root, int val) {
        if (!root) return 0;

        val = (val * 10) + root->val;
        
        if (!root->left && !root->right) {
            return val;
        }

        return findSum(root->left, val) + findSum(root->right, val);
    }
public:
    int sumNumbers(TreeNode* root) {
        return findSum(root, ); 
    }
};