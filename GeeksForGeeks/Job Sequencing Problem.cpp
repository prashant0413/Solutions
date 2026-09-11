// Approach 1
// TC = O(N log N)
// SC = O(N)
class DisjointSet {
  private:
    vector<int> parent;
  public:
    
    DisjointSet(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    
    int findUpar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUpar(parent[node]);
    }
    
    void unionSet(int u, int v) {
        int up = findUpar(u);
        int vp = findUpar(v);
        parent[up] = vp;
    }
};

class Jobs {
  public:
    int deadline;
    int profit;
};

class Solution {
  public:
    struct cmp {
      bool operator()(Jobs &j1, Jobs &j2) {
          return j1.profit > j2.profit;
      }  
    };
  
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        int maxDeadline = INT_MIN;
        vector<Jobs> arr(n);
        
        for (int i = 0; i < n; i++) {
            maxDeadline = max(maxDeadline, deadline[i]);
            arr[i].deadline = deadline[i];
            arr[i].profit = profit[i];
        }
        
        sort(begin(arr), end(arr), cmp());
        
        int cnt = 0;
        int netProfit = 0;
        DisjointSet ds(maxDeadline + 1);
        
        for (int i = 0; i < n; i++) {
            int slot = ds.findUpar(arr[i].deadline);
            
            if (slot > 0) {
                cnt++;
                netProfit += arr[i].profit;
                ds.unionSet(slot, slot - 1);
            }
        }
        
        return {cnt, netProfit};
    }
};
