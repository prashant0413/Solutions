// Approach 1
// TC = O(nlog(n))
// SC = O(n)
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int> pq; // max-heap
        for (int &i: stones) {
            pq.push(i);
        }

        while (pq.size() > 1) {
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            
            if (x == y) continue;
            pq.push(abs(y - x));
        }

        return pq.empty() ? 0 : pq.top();
    }
};
