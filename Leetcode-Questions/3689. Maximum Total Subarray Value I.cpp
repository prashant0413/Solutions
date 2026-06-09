// Approach 1
// TC = O(2N)
// SC = O(1)
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long maxi = *max_element(begin(nums), end(nums));
        long long mini = *min_element(begin(nums), end(nums));
        return (maxi - mini) * k;
    }
};
