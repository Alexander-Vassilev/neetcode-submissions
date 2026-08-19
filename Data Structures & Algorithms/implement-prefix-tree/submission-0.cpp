class PrefixTree {
    bool wordInserted = false;
    unordered_map<char, unique_ptr<PrefixTree>> queryMap;

public:
    PrefixTree() {
        wordInserted = false;
    }
    
    void insert(string word) {
        if (word.size() <= 0) return;

        PrefixTree* currTree = this;

        for (char c : word) {
            auto it = currTree->queryMap.find(c);

            if (it == currTree->queryMap.end()) {
                currTree->queryMap[c] = make_unique<PrefixTree>();

                it = currTree->queryMap.find(c);
            }

            currTree = it->second.get();
        }

        currTree->wordInserted = true;
    }
    
    bool search(string word) {
        if (word.size() <= 0) return false;

        PrefixTree* currTree = this;

        for (char c : word) {
            auto it = currTree->queryMap.find(c);

            if (it == currTree->queryMap.end()) {
                return false;
            }

            currTree = it->second.get();
        }

        return currTree->wordInserted;
    }
    
    bool startsWith(string prefix) {
        if (prefix.size() <= 0) return false;

        PrefixTree* currTree = this;

        for (char c : prefix) {
            auto it = currTree->queryMap.find(c);

            if (it == currTree->queryMap.end()) {
                return false;
            }

            currTree = it->second.get();
        }

        return true;
    }
};
