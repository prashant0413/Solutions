// APPROACH 1
// TC: O(N)
// SC: O(1)
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int m = firstList.size();
        int n = secondList.size();

        vector<vector<int>> res;
        int i = 0;
        int j = 0;
        while (i < m && j < n) {
            if (firstList[i][0] <= secondList[j][1] && secondList[j][0] <= firstList[i][1])
                res.push_back({max(firstList[i][0], secondList[j][0]), min(firstList[i][1], secondList[j][1])});
            if (firstList[i][1] < secondList[j][1]) i++;
            else j++;
        }

        return res;
    }
};
