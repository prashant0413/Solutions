// Approach 1
// TC = O(n^2) + O(2nlog(2n))
// SC = O(2n + k)
class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        vector<int> res;
        int n = a.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res.push_back(a[i] + b[j]);
            }
        }
        sort(res.begin(), res.end(), greater<int>());
        vector<int> ans(res.begin(), res.begin() + k);
        return ans;
    }
};

// Approach 2
// TC = O(nlog(n))
// SC = O(n)
class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());
        
        priority_queue<tuple<int, int, int>> pq;
        set<pair<int, int>> st;
        
        pq.push({a[0] + b[0], 0, 0});
        st.insert({0, 0});
        
        vector<int> ans;
        while (k-- && !pq.empty()) {
            auto [sum, i, j] = pq.top();
            pq.pop();
            ans.push_back(sum);
            if (i + 1 < n && !st.count({i + 1, j})) {
                pq.push({a[i + 1] + b[j], i + 1, j});
                st.insert({i + 1, j});
            }
            if (j + 1 < n && !st.count({i, j + 1})) {
                pq.push({a[i] + b[j + 1], i, j + 1});
                st.insert({i, j + 1});
            }
        }
        return ans;
    }
};
