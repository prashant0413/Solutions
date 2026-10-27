// APPROACH 1: BRUTE FOCE USING IN-BUILT NEXT PERMUTAION
// TC: O(N!)
// SC: O(1)
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(begin(nums), end(nums));
        int totalCombinations = 1;
        for (int i = 1; i <= n; i++) totalCombinations *= i;
        for (int i = 1; i <= totalCombinations; i++) {
            res.push_back(nums);
            next_permutation(begin(nums), end(nums));
        }

        return  res;
    }
};
