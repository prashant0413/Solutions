// APPROACH 1: RECURSION
// TC: O(2^N)
// SC: O(N)
class Solution {
    int solve(int i, vector<int> &height, int n, int cost) {
        if (i == n - 1) return cost;
        int left = solve(i + 1, height, n, cost + abs(height[i] - height[i + 1]));
        int right = i + 2 <= n - 1 ? solve(i + 2, height, n, cost + abs(height[i] - height[i + 2])) : INT_MAX;
        return min(left, right);
    }
public:
    int minCost(vector<int>& height) {
        int n = height.size();
        return solve(0, height, n, 0);
    }
};
