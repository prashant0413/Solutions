// Approach 1
// TC = O(N*N)
// SC = O(N)
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> freq(n + 1, 0);
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            freq[A[i]]++;
            freq[B[i]]++;
            int cnt = 0;
            for (int j = 1; j <= n; j++) {
                if (freq[j] == 2)
                    cnt++;
            }
            ans[i] = cnt;
        }
        return ans;
    }
};
