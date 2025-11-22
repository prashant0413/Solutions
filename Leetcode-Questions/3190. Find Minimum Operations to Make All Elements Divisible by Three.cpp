class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int mini = 0;
        for (auto &i : nums) {
            mini += (i % 3 == 1) ? 1 : (i % 3 == 2) ? 1 : 0 ;
        }
        return mini;   
    }
};
