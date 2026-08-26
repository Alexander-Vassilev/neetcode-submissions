class Solution {
public:
    class Trie {
    public:
        vector<unique_ptr<Trie>> tries;
        bool isWord = false;

        Trie () {
            tries = vector<unique_ptr<Trie>>(26);
        }

        void insert(string& s) {
            Trie* curr = this;
            int len = s.size();
            //cout << endl;

            for (int i = 0; i < len; i++) {
                int idx = s[i] - 'a';
                //cout << s[i] << endl;

                if (!curr->tries[idx]) curr->tries[idx] = make_unique<Trie>();

                curr = curr->tries[idx].get();
            }

            //cout << endl;
            curr->isWord = true;
        }

        vector<int> getMatches(string& s, int startIdx) {
            vector<int> matches{};
            Trie* curr = this;
            int currLen = 0;
            int len = s.size();
            ////cout << endl;

            for (int i = startIdx; i < len; i++) {
                int idx = s[i] - 'a';
                if (!curr->tries[idx]) return matches;
                curr = curr->tries[idx].get();
                currLen++;

                //cout << s[i] << endl;

                if (curr->isWord) {
                    matches.push_back(currLen);
                    //cout << "match found" << endl;
                }
            }

            return matches;
        }
    };

    bool dfs(Trie& trie, string& s, vector<bool>& possible, int startIdx) {
        if (!possible[startIdx]) return false;
        int len = s.size();
        if (startIdx == len) return true;

        //cout << "startIdx: " << startIdx << endl;
        vector<int> matches = trie.getMatches(s, startIdx);

        for (auto& match : matches) {
            if (dfs(trie, s, possible, startIdx + match)) return true;
        }

        possible[startIdx] = false;

        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        vector<bool> possible(s.size(), true);

        for (auto& word : wordDict) {
            trie.insert(word);
        }
        
        return dfs(trie, s, possible, 0);
    }
};
