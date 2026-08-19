class WordDictionary {
    bool containsWord = false;
    unordered_map<char, unique_ptr<WordDictionary>> queryMap;

public:
    WordDictionary() {
    }
    
    void addWord(string word) {
        WordDictionary* curr = this;

        for (char c : word) {
            auto it = curr->queryMap.find(c);

            if (it == curr->queryMap.end()) {
                curr->queryMap[c] = make_unique<WordDictionary>();
                it = curr->queryMap.find(c);
            }

            curr = it->second.get();
        }

        curr->containsWord = true;
    }
    
    bool search(string word) {
        WordDictionary* curr = this;

        for (int i = 0; i < word.size(); i++) {
            if (word[i] == '.') {
                for (const auto& entry : curr->queryMap) {
                    if (entry.second->search(word.substr(i + 1, word.size() - 1))) return true;
                }
            }

            auto it = curr->queryMap.find(word[i]);

            if (it == curr->queryMap.end()) {
                return false;
            }

            curr = it->second.get();
        }

        return curr->containsWord;
    }
};
