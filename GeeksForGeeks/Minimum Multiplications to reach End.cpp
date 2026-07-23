// Approach 1
// TC = O(m*n)
// SC = O(m)
class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        if (start == end) return 0;
        int n = arr.size();
        queue<pair<int, int>> q;
        vector<int> dist(1000, 1e9);
        dist[start] = 0;
        q.push({start, 0});
        int mod = 1000;
        while (!q.empty()) {
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            for (int i: arr) {
                int num = (node * i) % mod;
                if (steps + 1 < dist[num]) {
                    dist[num] = steps + 1;
                    if (num == end) return steps + 1;
                    q.push({num, steps + 1});
                }
            }
        }
        return -1;
    }
};
