// Approach 1 Fractional Knapsack
// TC = O(n + nlog(n))
// SC = O(2n)
class Solution {
  public:
    struct cmp {
        bool operator()(pair<int, int> &p, pair<int, int> &q) {
            return ((double)p.first / (double)p.second) > ((double)q.first / (double)q.second);
        }
    };
  
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({val[i], wt[i]});
        }
        
        sort(begin(arr), end(arr), cmp());
        
        double cost = 0.0;
        for (int i = 0; i < n; i++) {
            if (arr[i].second <= capacity) {
                cost += arr[i].first;
                capacity -= arr[i].second;
            } else {
                double c = ((double)arr[i].first / (double)arr[i].second) * capacity;
                cost += c;
                capacity = 0;
                break;
            }
        }
        
        cost = round(cost * 1000000.0) / 1000000.0;
        return cost;
    }
};
