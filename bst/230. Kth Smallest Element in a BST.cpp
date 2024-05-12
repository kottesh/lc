#include <iostream>
#include <stack>

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
    int kthSmallest(TreeNode* root, int k) {
        std::stack<TreeNode*> stk;
        
        int cnt = 0;
        while(!stk.empty() || root != nullptr) {
            while(root != nullptr) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            cnt++;
            if(cnt == k) {break;}
            stk.pop();
            root = root->right;
        }
        return root->val;
    }
};

int main() {
    Solution sol;
    TreeNode *root = nullptr;
    root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2); 

    std::cout << sol.kthSmallest(root, 1);
    return 0;
}