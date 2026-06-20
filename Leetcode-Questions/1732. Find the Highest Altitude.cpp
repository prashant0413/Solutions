// Approach 1
// TC = O(N)
// SC = O(1)
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int ha = max(0, gain[0]);
        int prev = gain[0];
        for (int i = 1; i < n; i++) {
            prev = gain[i] + prev;
            ha = max(ha, prev);
        }
        return ha;
    }
};
