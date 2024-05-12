#include <iostream>
#include <climits>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inorder(TreeNode *root) {
    if(root == nullptr)
        return;
    inorder(root->left);
    std::cout<<root->val<<" ";
    inorder(root->right); 
}
 
class Solution {
public:
    TreeNode *fixTree(TreeNode *root, TreeNode *min, TreeNode *max) {
        if(root == nullptr) {
            return root;
        }

        fixTree(root->left, min, root);

        if(root->val <= min->val) {
            std::swap(root, min);
        }
        else if(root->val >= max->val) {
            std::swap(root, max);
        }

        fixTree(root->right, root, max);

        return root;
    }

    void recoverTree(TreeNode* root) {
        root = fixTree(root, new TreeNode(INT_MIN), new TreeNode(INT_MAX));        
        inorder(root);
    }
};

int main() {

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->right = new TreeNode(2);

    Solution sol;
    sol.recoverTree(root);

    return 0;
}