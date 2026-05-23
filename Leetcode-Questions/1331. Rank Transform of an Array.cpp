// Approach 1
// TC = O(2N) + O(Nlog(N))
// SC = O(2N)
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int, int> mpp;
        priority_queue<int, vector<int>, greater<int>> pq;
        int rank = 0;
        int previous = INT_MIN;
        for (int i : arr) {
            pq.push(i);
        }

        while (!pq.empty()) {
            int ele = pq.top();
            pq.pop();
            if (ele == previous) {
                mpp[ele] = rank;
            } else {
                rank++;
                mpp[ele] = rank;
                previous = ele;
            }
        }

        vector<int> result;
        for (int& i : arr) {
            result.push_back(mpp[i]);
        }

        return result;
    }
};
