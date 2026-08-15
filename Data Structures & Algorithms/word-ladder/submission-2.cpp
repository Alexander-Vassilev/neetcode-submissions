class Solution {
public:
    void fillNodesList(string& word, set<string>& wordSet, unordered_map<string, vector<string>>& nodes, string& alphabet) {
        for (int i = 0; i < word.size(); i++) {
            string temp = word;

            for (int j = 0; j < alphabet.size(); j++) {
                char newChar = alphabet[j];
                
                if (newChar != word[i]) {
                    temp[i] = newChar;

                    if (wordSet.contains(temp)) nodes[word].push_back(temp);
                }
            }
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (!ranges::contains(wordList, endWord)) {
            return 0;
        }

        wordList.push_back(beginWord);
        int length = wordList.size();
        string alphabet = "abcdefghijklmnopqrstuvwxyz";
        stack<pair<string, int>> st;
        set<string> wordSet(wordList.begin(), wordList.end());
        unordered_map<string, vector<string>> nodes;
        set<string> seenSet;
        unordered_map<string, int> minDistances;

        for (int i; i < wordList.size(); i++) {
            fillNodesList(wordList[i], wordSet, nodes, alphabet);
        }

        minDistances[beginWord] = 1;
        seenSet.insert(beginWord);
        st.push({beginWord, 1});

        while (!st.empty()) {
            pair el = st.top();
            st.pop();
            string word = el.first;
            int distance = el.second;

            if (distance < minDistances[endWord] && minDistances[endWord] != 0) continue;

            //cout << word << endl;
            int newDistance = distance + 1;
            if (!seenSet.contains(word)) seenSet.insert(word);

            for (auto& node : nodes[word]) {
                bool isSeen = seenSet.contains(node);

                if (!isSeen || (minDistances[node] > newDistance)) {
                    st.push({node, newDistance});
                    seenSet.insert(node);
                    minDistances[node] = newDistance;
                    //cout << "node: " << node << " new distance: " << newDistance << endl;
                }
            }
        }

        return minDistances[endWord];
    }
};
