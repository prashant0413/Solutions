// Approach 1
// TC = O(n*log(n))
// SC = O(n)
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> vec(begin(nums), end(nums));
        sort(begin(vec), end(vec));

        int groupNum = 0;
        unordered_map<int, int> numGroup;
        numGroup[vec[0]] = groupNum;

        unordered_map<int, list<int>> groupList;
        groupList[groupNum].push_back(vec[0]);

        for (int i = 1; i < n; i++) {
            if (abs(vec[i] - vec[i - 1]) > limit) {
                groupNum++;
            }

            numGroup[vec[i]] = groupNum;
            groupList[groupNum].push_back(vec[i]);
        }

        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int g = numGroup[num];
            res[i] = groupList[g].front();
            groupList[g].pop_front();
        }
        return res;
    }
};
