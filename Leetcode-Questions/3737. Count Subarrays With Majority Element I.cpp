// Approach 1
// TC = O(N^2)
// SC = O(1)
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int c = 0;
            for (int j = i; j < n; j++) {
                if (target == nums[j]) c++;
                if (c > (j - i + 1) / 2) cnt++;
            }
        }
        return cnt;
    }
};

// Approach 2 computational improvement
// TC = O(N^2)
// SC = O(1)
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int c = 0;
            for (int j = i; j < n; j++) {
                if (target == nums[j]) c++;
                else c--;
                if (c > 0) cnt++;
            }
        }
        return cnt;
    }
};

// Approach 3
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
