 #include <iostream>
 #include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
    std::vector<int> result;
    void postorder(TreeNode *root) {
        if (!root) {
            postorder(root->left);
            postorder(root->right);
            result.push_back(root->val);
        }
    }
public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return result;
    }
};