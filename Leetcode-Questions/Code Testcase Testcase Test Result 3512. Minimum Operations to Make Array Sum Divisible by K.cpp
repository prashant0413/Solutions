// Approach 1
// TC = O(N)
// SC = O(1)
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long sum = 0;
        for (int &i : nums)
            sum += i;
        return sum % k;
    }
};
