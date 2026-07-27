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

// Approach 2
// TC = O(n)
// SC = O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int a = nums[0];
        int b = nums[1];
        int maxi = (a - 1) * (b - 1);
        for (int i = 2; i < nums.size(); i++) {
            if (a < b && nums[i] > a) {
                a = nums[i];
                maxi = max(maxi, (a - 1) * (b - 1));
            } else if (nums[i] > b) {
                b = nums[i];
                maxi = max(maxi, (a - 1) * (b - 1));
            }
        }
        return maxi;
    }
};
