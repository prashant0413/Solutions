class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l,r;
        l = r = 0;
        int maxLen = 0;
        unordered_map<int, int> mpp;
        while (r < fruits.size()) {
            mpp[fruits[r]]++;
            if (mpp.size() > 2) {
                mpp[fruits[l]]--;
                if (mpp[fruits[l]] == 0)
                    mpp.erase(fruits[l]);
                l++;
            }
            if (mpp.size() <= 2)
                maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};
