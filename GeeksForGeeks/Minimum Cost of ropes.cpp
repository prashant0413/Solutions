// Approach 1
// TC = O(n * n log(n))
// SC = O(n)
class Solution {
  public:
    int minCost(vector<int>& arr) {
        if (arr.size() == 1)
            return 0;
            
        sort(arr.begin(), arr.end());
        int cost = 0;
        int i = 0;
        while (true) {
            int k = arr[i] + arr[i + 1];
            cost += k;
            i += 2;
            if (i >= arr.size())
                break;
            arr.push_back(k);
            sort(arr.begin(), arr.end());
        }
        return cost;
    }
};

// Approach 2
// TC = O(nlog(n))
// SC = O(n)
class Solution {
  public:
    int minCost(vector<int>& arr) {
        if (arr.size() == 1)
            return 0;
            
        priority_queue<int, vector<int>, greater<>> pq;
        for (int &i : arr)
            pq.push(i);
            
        int cost = 0;
        while (!pq.empty()) {
            int p = pq.top();
            pq.pop();
            if (pq.empty())
                break;
            int q = pq.top();
            pq.pop();
            int k = p + q;
            cost += k;
            pq.push(k);
        }
        return cost;
    }
};
