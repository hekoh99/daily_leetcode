struct Node {
    Node *next[26] = {};
    bool isEnd = false;
};

class Trie {
    Node root;

public:
    Trie() {

    }
    
    void insert(string word) {
        Node *node = &root;
        for(int i=0;i<word.length();i++) {
            if (node->next[word[i] - 'a'] == NULL) {
                node->next[word[i] - 'a'] = new Node();
            }
            node = node->next[word[i] - 'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        bool res = true;
        Node *node = &root;
        for(int i=0;i<word.length();i++) {
            if (node->next[word[i] - 'a'] == NULL) {
                res = false;
                break;
            }
            node = node->next[word[i] - 'a'];
        }
        if (node->isEnd == false) {
            res = false;
        }
        return res;
    }
    
    bool startsWith(string prefix) {
        bool res = true;
        Node *node = &root;
        for(int i=0;i<prefix.length();i++) {
            if (node->next[prefix[i] - 'a'] == NULL) {
                res = false;
                break;
            }
            node = node->next[prefix[i] - 'a'];
        }
        return res;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */