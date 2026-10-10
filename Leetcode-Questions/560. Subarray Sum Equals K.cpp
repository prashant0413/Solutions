// APPROACH 1: BRUTE FORCE
// TC: O(N^2)
// SC: O(1)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum == k) cnt++;
            }
        }

        return cnt;
    }
};

// APPROACH 2: USING HASHMAP
// TC: O(N)
// SC: O(N)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        int cnt = 0;
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (mpp.count(sum - k)) {
                cnt += mpp[sum - k];
            }
            mpp[sum] += 1;
        }
        
        return cnt;
    }
};
