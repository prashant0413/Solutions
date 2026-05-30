// Approach 1
// TC = O(nlog(n))
// SC = O(n)
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
        priority_queue<int> pq; // max-heap
        for (int i: piles)
            pq.push(i);
        
        while (!pq.empty() && k) {
            int ele = pq.top(); pq.pop();
            ele = ceil(ele / 2.0);
            if (ele > 0)
                pq.push(ele);
            k--;
        }

        int stones = 0;
        while (!pq.empty()) {
            stones += pq.top(); pq.pop();
        }
        return stones;
    }
};
