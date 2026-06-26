// Approach 1
// TC = O(N)
// SC = O(N)
class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, long long> mpp;
        long long cumSum = 0;
        mpp[cumSum] = 1;
        long long ans = 0;
        int validLeftPoints = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                validLeftPoints += mpp[cumSum];
                cumSum++;
            } else {
                cumSum--;
                validLeftPoints -= mpp[cumSum];
            }
            mpp[cumSum]++;
            ans += validLeftPoints;
        }
        return ans;
    }
};
