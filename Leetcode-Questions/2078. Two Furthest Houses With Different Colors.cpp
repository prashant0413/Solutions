// Approach 1
// TC = O(n^2)
// SC = O(1)
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int maxi = -1;
        for (int i = 0; i < colors.size(); i++) {
            for (int j = i + 1; j < colors.size(); j++) {
                if (colors[i] != colors[j]) {
                    maxi = max(maxi, abs(i - j));
                }
            }
        }
        return maxi;
    }
};
