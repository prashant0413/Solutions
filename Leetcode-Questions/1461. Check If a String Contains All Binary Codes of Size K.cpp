// Approach 1
// TC = O(N * K)
// SC = O(2^K * K)
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;
        int n = s.length();
        int cnt = 1 << k; // pow(2, k);
        for (int i = k; i <= n; i++) {
            string sub = s.substr(i - k, k);
            if (!st.count(sub)) {
                st.insert(sub);
                cnt--;
            }

            if (cnt == 0)
                return true;
        }
        return false;
    }
};
