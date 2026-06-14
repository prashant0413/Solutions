// Approach 1
// TC = O(N^2)
// SC = O(1)
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        for (string &s: words) {
            int w = 0;
            for (int i = 0; i < s.length(); i++) {
                w += weights[s[i] - 'a'];
            }
            int c = w % 26;
            ans += (char)('z' - c);
        }
        return ans;
    }
};
