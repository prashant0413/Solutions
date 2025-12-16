// Approach 1
// TC = O(2n)
// SC = O(n)
class Solution {
public:
    int M = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> mpp_left;
        unordered_map<int, int> mpp_right;

        for (int &i : nums) {
            mpp_right[i]++;
        }

        int result = 0;
        for (int &i : nums) {
            mpp_right[i]--;
            int left = mpp_left[i * 2];
            int right = mpp_right[i * 2];
            result = (result + (1LL * left * right)) % M;
            mpp_left[i]++;
        }
        return result;
    }
};

// Approach 2
// TC = O(n)
// SC = O(n)
class Solution {
public:
    int mod = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> validI;
        unordered_map<int, int> validJ;

        int result = 0;
        for (int &i : nums) {
            if (i % 2 == 0) {
                result = (result + validJ[i / 2]) % mod;
            }

            validJ[i] = (validJ[i] + validI[i * 2]) % mod;
            validI[i]++;
        }
        return result;
    }
};
