// Approach 1 brute force
// TC = O(N^2)
// SC = O(1)
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 1;
        for (; ; i++) {
            bool pre = false;
            for (int e: nums) {
                if (k * i == e) {
                    pre = true;
                    break;
                }
            }
            if (!pre)
                return i * k;
        }        
        return 0;
    }
};

// Approach 2 using set
// TC = O(N)
// SC = O(N)
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(), nums.end());
        int i = 1;
        while (st.count(k * i) == 1) {
            i++;
        }
        return i * k;
    }
};
