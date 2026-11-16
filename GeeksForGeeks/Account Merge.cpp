// APPROACH 1: DISJOINT SET TECHNIQUE
// TC: O(A . E LOG E) 
// SC: O(A + E)
class DisjointSet {
    vector<int> size;
    vector<int> parent;
public:
    DisjointSet(int n) {
        size = vector<int>(n, 1);
        parent = vector<int>(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    
    int findUpar(int node) {
        return node == parent[node] ? node : parent[node] = findUpar(parent[node]);
    }
    
    void unionBySize(int u, int v) {
        int up_u = findUpar(u);
        int up_v = findUpar(v);
        if (up_u == up_v) return;
        if (size[up_u] < size[up_v]) {
            size[up_v] += size[up_u];
            parent[up_u] = up_v;
        } else {
            size[up_u] += size[up_v];
            parent[up_v] = up_u;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accMerge(vector<vector<string>>& arr) {
        int n = arr.size();
        DisjointSet ds(n);
        unordered_map<string, int> mpp;
        // O(A + E)
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < arr[i].size(); j++) {
                string email = arr[i][j];
                if (mpp.count(email)) {
                    ds.unionBySize(mpp[email], i);
                } else {
                    mpp[email] = i;
                }
            }
        }
        
        vector<string> mergeMail[n];

        // O(E)
        for (auto it: mpp) {
            string mail = it.first;
            int node = ds.findUpar(it.second);
            mergeMail[node].push_back(mail);
        }


        // O(A + E LOG E)
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (mergeMail[i].empty()) continue;
            vector<string> temp;
            temp.push_back(arr[i][0]);
            sort(begin(mergeMail[i]), end(mergeMail[i]));
            for (auto it: mergeMail[i]) temp.push_back(it);
            ans.push_back(temp);
        }
        
        return ans;
    }
};
