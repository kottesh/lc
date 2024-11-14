#include <bits/stdc++.h>

struct Node {
    Node *links[26];
    bool flag;
    int count;

    Node() {
        for (int i = 0; i < 26; i++)
            links[i] = nullptr;
        flag = false;
        count = 0;
    }

    bool containsKey(char chr) {
        return (this->links[chr - 'a']) != nullptr;
    }

    void put(char ch) {
        links[ch - 'a'] = new Node;
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
        this->root = new Node();
    }

    void insert(std::string word) {
        Node *node = root;

        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch);
            }
            node = node->get(ch);
            node->count++;
        }
        node->setEnd();
    }

    int count(std::string word) {
        int count = 0;
        Node *curr = root;

        for (char chr : word) {
            curr = curr->get(chr);
            count += curr->count; 
        }

        return count;
    }
};


class Solution {
public:
    std::vector<int> sumPrefixScores(std::vector<std::string>& words) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(0); std::cout.tie(0);

        Trie *trie = new Trie();
        
        for (std::string word : words)
            trie->insert(word);

        std::vector<int> res;

        for (std::string word : words)
            res.push_back(trie->count(word)); 
        
        return res;
    }

    //std::vector<int> sumPrefixScores(std::vector<std::string>& words) {
    //    std::ios_base::sync_with_stdio(false);
    //    std::cin.tie(0); std::cout.tie(0);

    //    std::vector<int> res (words.size(), 0);
    //    std::unordered_map<std::string, int> store;
    //    
    //    for (std::string word : words) {
    //        std::string prefix = "";
    //        for (char ch : word) {
    //            prefix += ch;
    //            store[prefix]++;
    //        }
    //    } 
    //    
    //    int j = 0;
    //    for (std::string word : words) {
    //        std::string prefix = "";
    //        for (char ch : word) {
    //            prefix += ch;
    //            res[j] += store[prefix]; 
    //        }
    //        j++;
    //    }

    //    return res;
    //}

    //std::vector<int> sumPrefixScores(std::vector<std::string>& words) {
    //    std::ios_base::sync_with_stdio(false);
    //    std::cin.tie(0); std::cout.tie(0);

    //    std::unordered_set<std::string> store;
    //        
    //    std::vector<int> res(words.size());
    //    
    //    int j = 0;
    //    for (auto word: words) {
    //        for (int i = 1; i <= word.length(); i++) {
    //            std::string temp = word.substr(0, i);
    //            if (store.find(temp) == store.end()) {
    //                store.insert(temp);
    //            } 
    //        }
    //        for (auto item : words) {
    //            for (int i = 1; i <= item.length(); i++) {
    //                std::string temp = item.substr(0, i);
    //                if (store.find(temp) != store.end()) {
    //                    res[j]++;
    //                }
    //            }
    //        }
    //        store.clear();
    //        ++j;
    //    }

    //    return res;
    //}
};

int main() {
    std::vector<std::string> in {"abc","ab","bc","b"};
    std::vector<int> res = (new Solution())->sumPrefixScores(in);

    for (auto val : res) {
        std::cout << val << std::endl;
    }
}

