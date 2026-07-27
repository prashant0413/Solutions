// Approach 1
// TC = O(nlog(n))
// SC = O(n)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq;
        for (int i: nums)
            pq.push(i);
        int a = pq.top() - 1; pq.pop();
        int b = pq.top() - 1; pq.pop();
        return a * b;
    }
};
