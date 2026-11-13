// APPROOACH 1: BFS
// TC: O(26.K.N)
// SC: O(N)
class Solution {
  public:
    int wordLadder(vector<string> &words, string &start, string &end) {
        unordered_set<string> st;
        for (string str: words) st.insert(str);
        queue<pair<string, int>> q;
        q.push({start, 1});
        st.erase(start);
        
        while (!q.empty()) {
            auto it = q.front(); q.pop();
            string str = it.first;
            int steps = it.second;
            if (str == end) return steps;
            
            for (int i = 0; i < str.length(); i++) {
                char org = str[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    str[i] = c;
                    if (st.count(str)) {
                        q.push({str, steps + 1});
                        st.erase(str);
                    }
                }
                str[i] = org;
            }
        }
        
        return 0;
    }
};
