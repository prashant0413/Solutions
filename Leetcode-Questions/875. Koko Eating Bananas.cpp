// APPROACH 1: USING BINARY SEARCH
// TC: O(N LOG N)
// SC: O(1)
class Solution {
public:
    bool canEatAll(vector<int>& piles, int h, int k) {
        int timeSpend = 0;
        for (int i: piles) {
            timeSpend += ceil((double)i / (double)k);
            if (timeSpend > h) return false;
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int low  = 1;
        int high = *max_element(begin(piles), end(piles));
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canEatAll(piles, h, mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
