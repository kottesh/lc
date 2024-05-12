#include <iostream>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* Approach 1
class Solution {
    int diameter=0;
public:
    int findHeight(TreeNode* root) {
        if(!root) return 0;
        return 1 + std::max(findHeight(root->left), findHeight(root->right));
    }

    void gotoNode(TreeNode *root) {
        if(root) {
            int temp = findHeight(root->left) + findHeight(root->right);
            if(diameter < temp) {diameter = temp;}
            gotoNode(root->left);
            gotoNode(root->right);
        }
    }

    int diameterOfBinaryTree(TreeNode* root) {
        gotoNode(root);
        return diameter;
    }
};    
*/


// Approach 2 or Code refactored. hehehehe!!! 
class Solution {
    int diameter=0;
public:
    int findDiameter(TreeNode *root) {
        if(!root) return 0;
        int lH, rH;
        lH = findDiameter(root->left); 
        rH = findDiameter(root->right);
        diameter = ((lH + rH) > diameter) ? (lH + rH) : diameter;

        return 1 + std::max(lH, rH);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        findDiameter(root);
        return diameter;
    }
};

int main() {
}