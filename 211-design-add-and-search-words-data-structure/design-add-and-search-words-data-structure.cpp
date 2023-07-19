class TrieNode {
public:
    vector<TrieNode *> nodes;
    bool isWord = false;
    TrieNode() {
        nodes = vector<TrieNode *>(26, NULL);
    }
};

class WordDictionary {
public:
    TrieNode *root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *ref = root;
        for (int i = 0; i < word.size(); i++) {
            int pos = word[i] - 'a';
            if (ref->nodes[pos] == NULL) {
                ref->nodes[pos] = new TrieNode();
            }
            ref = ref->nodes[pos];
        }
        ref->isWord = true;
    }
    
    bool backTrack(int index, string word, TrieNode *newRef) {
        if (newRef == NULL) return false;
        if (index == word.size()) return newRef->isWord;
        // cout << index << " " << word[index] << endl;
        TrieNode *ref = newRef;
        if (word[index] == '.') {
            for (int i = 0; i < 26; i++) {
                if (ref->nodes[i] != NULL && backTrack(index + 1, word, ref->nodes[i])) {
                    return true;
                } 
            }
        } else {
            int i = word[index] - 'a';
            if (ref->nodes[i] != NULL && backTrack(index + 1, word, ref->nodes[i])) {
                return true;
            }
        }
        
        return false;
    }

    bool search(string word) {
        // cout << "new search " << word << endl;
        bool res =  backTrack(0, word, root);
        // cout << "res " << res << endl;
        return res;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */