// APPROACH 1: DE BRUIJN SEQUENCE
// TC: O(K^N)
// SC: O(N)
class Solution {
    void dfs(string start, int n, int k, vector<int> &edges, unordered_set<string> &vis) {
        for (int i = 0; i < k; i++) {
            string newNode = start + (char)(i + '0');
            if (vis.count(newNode)) continue;
            vis.insert(newNode);
            dfs(newNode.substr(1), n, k, edges, vis);
            edges.push_back(i);
        }
    }

    string solve(int n, int k) {
        unordered_set<string> vis;
        vector<int> edges;

        string start = string(n - 1, '0');
        dfs(start, n, k, edges, vis);

        string ans = "";
        int totalSubstrings = pow(k, n);
        for (int i = 0; i < totalSubstrings; i++) {
            ans += (char)(edges[i] + '0');
        }
        ans += start;
        return ans;
    }
public:
    string crackSafe(int n, int k) {
        return solve(n, k);
    }
};
