#include <iostream>

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr) {
            return new TreeNode(val);
        } if(val > root->val) {
            root->right = insertIntoBST(root->right, val);
        } else if(val < root->val) {
            root->left = insertIntoBST(root->left, val);
        }
        return root;
    }
};

void inorder(TreeNode *root) {
    if(root == nullptr)
        return;
    inorder(root->left);
    std::cout<<root->val;
    inorder(root->right);
}

int main() {
    Solution sol;

    TreeNode *root = nullptr;

    root = sol.insertIntoBST(root, 5);
    root = sol.insertIntoBST(root, 6);
    root = sol.insertIntoBST(root, 4);
    root = sol.insertIntoBST(root, 12);
    root = sol.insertIntoBST(root, 0);
    root = sol.insertIntoBST(root, 1);
    root = sol.insertIntoBST(root, 78);
    std::cout<<root->val;    
    inorder(root);    
}