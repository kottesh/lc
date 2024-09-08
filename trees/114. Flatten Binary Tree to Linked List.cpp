#include <bits/stdc++.h>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
typedef TreeNode* Node;
 
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;

        std::stack<Node> store;
        Node root_t = root;
        root = nullptr;
        Node tracker = nullptr;
        
        store.push(root_t);
        while (!store.empty()) {
            Node curr = store.top();
            store.pop();

            if (curr->right != nullptr) {
                store.push(curr->right);
                curr->right = nullptr;
            }
            if (curr->left != nullptr) {
                store.push(curr->left);
                curr->left = nullptr;
            }
            
            if (!root) {
                root = curr; 
                tracker = root;
            } else {
                tracker->right = curr;
                tracker = tracker->right;
            }
        }
    }
};

int main() {
    return 0;
}

