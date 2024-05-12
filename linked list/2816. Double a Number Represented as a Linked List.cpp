#include <bits/stdc++.h>

typedef ListNode Node;

class Solution {
   std::stack<Node*> store;
public:
    ListNode* doubleIt(ListNode* head) {
		if (!head) return head;

		Node* curr = head;
		while (curr) {
			store.push(curr);
			curr = curr->next;
		}

		int rem = 0;

		while (!store.empty()) {
			Node* curr = store.top();
			store.pop();
			int val = curr->val * 2;
			val += rem;
			if (val > 9) {
				curr->val = val % 10;
				rem = val / 10;
			} else {
				curr->val = val;
				rem = 0;
			}
		}

		if (rem != 0) {
			Node* node = new Node(rem);
			node->next = head;
			head = node;
		}
		return head;
    }
};
