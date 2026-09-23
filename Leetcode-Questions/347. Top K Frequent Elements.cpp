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

// APPROACH 2: USING HASHMAP AND SORTING
// TC: O(N LOG N)
// SC: O(N)
class Solution {
public:
    struct cmp {
        bool operator()(pair<int, int> &p1, pair<int, int>  &p2) {
            return p1.second > p2.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for (int &i: nums)
            mpp[i]++;

        vector<pair<int, int>> arr;
        for (auto i: mpp) {
            arr.push_back(i);
        }

        sort(begin(arr), end(arr), cmp());

        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(arr[i].first);
        }

        return ans;
    }
};

// APPROACH 3: USING BUCKET TECHNIQUE
// TC: O(4N)
// SC: O(2N)
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
