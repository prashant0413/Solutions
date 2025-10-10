// Map approach
// TC = O(n) = O(nlog(n)) sometimes
// SC = O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }

        for (auto it : mpp) {
            if (it.second == 1)
                return it.first;
        }
        return -1;
    }
};

// Optimal Soltions using concept of buckets
// TC = O(N)
// SC = O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0;
        int twos = 0;
        for (int i = 0; i < nums.size(); i++) {
            ones = (ones ^ nums[i]) & (~twos);
            twos = (twos ^ nums[i]) & (~ones);
        }
        return ones;
    }
};
