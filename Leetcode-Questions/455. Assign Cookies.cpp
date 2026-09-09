// Approach 1
// TC = O(Nlog(N))
// SC = O(1)
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n1 = g.size();
        int n2 = s.size();

        sort(begin(g), end(g));
        sort(begin(s), end(s));

        int cnt = 0;
        int i = 0;
        int j = 0;

        while (i < n1 && j < n2) {
            if (g[i] <= s[j]) {
                cnt++;
                i++;
                j++;
            } else if (s[j] < g[i]) {
                j++;
            }
        }

        return cnt;
    }
};
