// Approach 1 give TLE on leetcode
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
