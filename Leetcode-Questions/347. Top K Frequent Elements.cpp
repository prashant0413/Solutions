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
