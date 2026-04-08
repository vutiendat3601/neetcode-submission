class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool is_word = 0;
};

class PrefixTree {
private:
    TrieNode* root = new TrieNode();

public:
    PrefixTree() {}
    
    void insert(string word) {
        auto cur = root;
        for (auto &c : word) {
            if (!cur->children.count(c)) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->is_word = 1;
    }
    
    bool search(string word) {
        auto cur = root;
        for (auto &c : word) {
            if (!cur->children.count(c)) {
                return 0;
            }
            cur = cur->children[c];
        }
        return cur->is_word;
    }
    
    bool startsWith(string prefix) {
        auto cur = root;
        for (auto &c : prefix) {
            if (!cur->children.count(c)) {
                return 0;
            }
            cur = cur->children[c];
        }
        return 1;
    }
};
