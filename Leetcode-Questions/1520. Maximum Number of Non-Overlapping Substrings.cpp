// Approach 1 using kosaraju's algorithm
// TC = O(N)
// SC = O(N)
class Solution {
private:
    void dfs(char node, stack<char> &st, vector<bool> &vis, map<char, set<char>> &adj) {
        vis[node - 'a'] = true;
        for (auto it: adj[node]) {
            if (!vis[it - 'a']) {
                dfs(it, st, vis, adj);
            }
        }
        st.push(node);
    }

    void redfs(char node, map<char, set<char>> &adj, vector<bool> &vis, string &temp) {
        vis[node - 'a'] = true;
        temp.push_back(node);
        for (auto it: adj[node]) {
            if (!vis[it - 'a']) {
                redfs(it, adj, vis, temp);
            }
        }
    }
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();

        // 1. first and last occurences of each character in string
        unordered_map<char, pair<int, int>> pos;
        for (int i = 0; i < n; i++) {
            if (pos.count(s[i]) == 0) {
                pos[s[i]] = {i, i};
            } else {
                pos[s[i]].second = i;
            }
        }

        // 2. Building the graph
        map<char, set<char>> adj;
        for (auto it: pos) {
            char c = it.first;
            int f = it.second.first;
            int l = it.second.second;
            for (int i = f + 1; i < l; i++) {
                if (s[i] != c) {
                    adj[c].insert(s[i]);
                }
            }
        }

        // 3. Applying Kosaraju's algorithm
        stack<char> st;
        vector<bool> vis(26, false);
        for (auto it: pos) {
            char node = it.first;
            if (!vis[node - 'a']) {
                dfs(node, st, vis, adj);
            }
        }

        // 4. reversing the edges
        fill(begin(vis), end(vis), false);
        map<char, set<char>> rev;
        for (auto it: adj) {
            char node = it.first;
            for (auto i: adj[node]) {
                rev[i].insert(node);
            }
        }

        // 5. Second dfs traversal
        string temp = "";
        vector<string> comp;
        while (!st.empty()) {
            char node = st.top(); st.pop();
            if (!vis[node - 'a']) {
                if (!temp.empty()) {
                    comp.push_back(temp);
                    temp.clear();
                }
                redfs(node, rev, vis, temp);
            }
        }
        if (!temp.empty()) comp.push_back(temp);

        // 6. checking outdegree and push into the answer
        vector<string> ans;
        for (string t: comp) {
            bool valid = true;
            for (char c: t) {
                for (char in: adj[c]) {
                    if (t.find(in) == string::npos) {
                        valid = false;
                        break;
                    }
                }
                if (!valid) break;
            }
            if (valid) {
                int mini = INT_MAX, maxi = INT_MIN;
                for (char c: t) {
                    mini = min(mini, pos[c].first);
                    maxi = max(maxi, pos[c].second);
                }
                ans.push_back(s.substr(mini, maxi - mini + 1));
            }
        }
        
        return ans;
    }
};
