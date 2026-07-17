// Approach 1
// TC = O(V + E)
// SC = O(V)
class Solution {
  public:
    string findOrder(vector<string> &words) {
        vector<int> adj[26];
        int cnt = 0;
        int present[26] = {0};
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].length(); j++) {
                if (present[words[i][j] - 'a'] == 0) {
                    present[words[i][j] - 'a'] = 1;
                    cnt++;
                }
            }
        }
        int indegree[26] = {0};
        for (int i = 0; i < words.size() - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];
            
            bool found = false;
            
            for (int j = 0; j < min(s1.size(), s2.size()); j++) {
                if (s1[j] == s2[j]) continue;
                int u = s1[j] - 'a';
                int v = s2[j] - 'a';
                
                if (find(begin(adj[u]), end(adj[u]), v) == adj[u].end()) {
                    adj[u].push_back(v);
                    indegree[v]++;
                }
                found = true;
                break;
            }
            
            if (!found && s1.size() > s2.size()) {
                return "";
            }
        }
        
        string ans;
        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (indegree[i] == 0 && present[i]) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans += char(node + 'a');
            
            for (int i: adj[node]) {
                if (--indegree[i] == 0) {
                    q.push(i);
                }
            }
        }
        
        return ans.length() == cnt ? ans : "";
    }
};
