// APPROACH 1: USING MAX-HEAP
// TC: O(N LOG N)
// SC: O(N)
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int i: stones) pq.push(i);

        while (pq.size() > 1) {
            int p = pq.top(); pq.pop();
            int q = pq.top(); pq.pop();
            if (p == q) continue;
            pq.push(abs(p - q));
        }

        return pq.empty() ? 0 : pq.top();
    }
};
