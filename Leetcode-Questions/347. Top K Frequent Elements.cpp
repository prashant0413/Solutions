// Approach 1
// TC = O(n) + (O(nlog(k)) => O(nlog(n)) Worst Case) + (O(k) => O(n) worst case)
// SC = O(n) + O(k)
class Solution {
public:
    typedef pair<int, int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for (int &num : nums) {
            mpp[num]++;
        }
        priority_queue<P, vector<P>, greater<P>> pq;
        for (auto &i : mpp) {
            int val = i.first;
            int freq = i.second;
            pq.push({freq, val});
            if (pq.size() > k)
                pq.pop();
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

// Approach 2
// TC = O(4n)
// SC = O(n) + O(k)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        for (int &num : nums) {
            mpp[num]++;
        }

        vector<vector<int>> bucket(n + 1);
        for (auto &i : mpp) {
            int val = i.first;
            int freq = i.second;
            bucket[freq].push_back(val);
        }

        vector<int> ans;
        for (int i = n; i >= 0; i--) {
            if (bucket[i].empty())
                continue;

            while (!bucket[i].empty() && k > 0) {
                ans.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }
        return ans;
    }
};
