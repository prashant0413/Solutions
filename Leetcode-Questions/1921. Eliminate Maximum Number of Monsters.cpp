// Approach 1 using greedy
// TC = O(nlog(n))
// SC = O(n)
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> timeTaken(n);
        for (int i = 0; i < n; i++) {
            timeTaken[i] = ceil(dist[i] / (double)speed[i]);
        }
        sort(begin(timeTaken), end(timeTaken));

        int time = 1;
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (timeTaken[i] - time <= 0) return cnt;
            cnt++;
            time++;
        }
        return cnt;
    }
};
