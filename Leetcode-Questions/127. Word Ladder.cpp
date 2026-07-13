// Approach 1
// TC = O(N*K)
// SC = O(N)
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        int k = beginWord.size();
        set<string> st;
        for (int i = 0; i < n; i++) {
            st.insert(wordList[i]);
        }

        // if end word is not present in word list
        if (st.count(endWord) == 0) return 0;

        if (st.count(beginWord))
            st.erase(beginWord);
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            // will always return steps if end word is present in the list
            if (word == endWord) return steps;

            for (int i = 0; i < k; i++) {
                char original = word[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    if (st.count(word)) {
                        q.push({word, steps + 1});
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};
