#include <bits/stdc++.h>

struct Node {
    Node *links[26];    
    bool flag;

    Node() {
        flag = false;
        
        for (int i = 0; i < 26; i++)
            links[i] = nullptr;
    }

    bool containsKey(char ch) {
        return (this->links[ch - 'a'] != nullptr);
    }

    void put(char ch) {
        this->links[ch - 'a'] = new Node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        this->flag = true;
    }
};

class Trie {
private:
    Node *root;
public:
    Trie() {
        this->root = new Node;
    }
    
    void insert(std::string word) {
        Node *node = root;

        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch);
            }
            node = node->get(ch);
        }    
        node->setEnd();
    }
    
    bool search(std::string word) {
        Node* node = root;

        for (char ch : word) {
            if (!node->containsKey(ch))
                return false;
            node = node->get(ch);
        }

        return node->flag;
    }
    
    bool startsWith(std::string prefix) {
        Node *node = root;

        for (char ch : prefix) {
            if (!node->containsKey(ch)) {
                return false;
            }
            node = node->get(ch);
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
