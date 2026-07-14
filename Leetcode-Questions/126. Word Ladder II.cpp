// Approach 1 gives TLE on leetcode
// TC and SC is depends on the test cases cannot be generalized
class Solution {
public:
    typedef vector<vector<string>> VVS;
    typedef vector<string> VS;

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        int k = beginWord.size();
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        VVS res;

        // if endWord not in the list
        if (st.count(endWord) == 0) return res;

        queue<VS> q;
        q.push({beginWord});
        while (!q.empty()) {
            int size = q.size();

            // for storing words to be deleted
            vector<string> delWords;

            for (int i = 0; i < size; i++) {
                VS sequence = q.front();
                string word = sequence.back();
                q.pop();

                if (word == endWord) {
                    res.push_back(sequence);
                    continue;
                }

                for (int j = 0; j < k; j++) {
                    char org = word[j];
                    for (int c = 'a'; c <= 'z'; c++) {
                        word[j] = c;
                        if (st.count(word)) {
                            delWords.push_back(word);
                            sequence.push_back(word);
                            q.push(sequence);
                            sequence.pop_back();
                        }
                    }
                    word[j] = org;
                }
            }

            // now deleting words that are used
            for (string w: delWords) {
                st.erase(w);
            }
        }
        return res;
    }
};

// Approach 2 leetcode accepted
// Not recommended for interview
class Solution {
    unordered_map<string, int> mpp;
    vector<vector<string>> ans;
    string b;

    void dfs(string word, vector<string> &seq) {
        if (word == b) {
            reverse(begin(seq), end(seq));
            ans.push_back(seq);
            reverse(begin(seq), end(seq));
            return;
        }

        int steps = mpp[word];
        for (int i = 0; i < word.size(); i++) {
            char org = word[i];
            for (char c = 'a'; c <= 'z'; c++) {
                word[i] = c;
                if (mpp.count(word) && mpp[word] + 1 == steps) {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = org;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        int k = beginWord.size();

        unordered_set<string> st(begin(wordList), end(wordList));
        st.erase(beginWord);
        mpp[beginWord] = 1;
        queue<string> q;
        b = beginWord;
        q.push(beginWord);
        while (!q.empty()) {
            string word = q.front();
            int steps = mpp[word];
            q.pop();

            if (word == endWord) break;

            for (int i = 0; i < k; i++) {
                char org = word[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    if (st.count(word)) {
                        mpp[word] = steps + 1;
                        st.erase(word);
                        q.push(word);
                    }
                }
                word[i] = org;
            }
        }

        if (mpp.count(endWord)) {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }
        return ans;
    }
};
