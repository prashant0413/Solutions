// Approach 1
// TC = O(n*m*log(m))
// SC = O(m+n)
class DisjointSet {
    vector<int> size;
    vector<int> parent;
public:
    DisjointSet(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int fp(int node) {
        if (node == parent[node]) return node;
        return parent[node] = fp(parent[node]);
    }

    void unionBySize(int u, int v) {
        int upu = fp(u);
        int upv = fp(v);
        if (upu == upv) return;
        if (size[upu] < size[upv]) {
            size[upv] += size[upu];
            parent[upu] = upv;
        } else {
            size[upu] += size[upv];
            parent[upv] = upu;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        DisjointSet ds(n);
        unordered_map<string, int> mpp;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (mpp.count(accounts[i][j])) {
                    ds.unionBySize(mpp[accounts[i][j]], i);
                } else {
                    mpp[accounts[i][j]] = i;
                }
            }
        }

        vector<string> mergeMail[n];
        for (auto it: mpp) {
            string mail = it.first;
            int node = ds.fp(it.second);
            mergeMail[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (mergeMail[i].empty()) continue;
            sort(begin(mergeMail[i]), end(mergeMail[i]));
            string name = accounts[i][0];
            vector<string> temp;
            temp.push_back(name);
            for (auto t: mergeMail[i]) {
                temp.push_back(t);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};
