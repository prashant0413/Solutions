// Approach 1: KMP ALGORITHM OF STRING MATCHING
// TC: O(N + M)
// SC: O(M)
class Solution {
  private:
    void buildLps(vector<int> &lps, string &pat, int m) {
        int i = 1;
        int len = 0;
        lps[0] = 0;
        while (i < m) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
  public:
    vector<int> search(string &pat, string &txt) {
        int n = txt.size();
        int m = pat.size();
        
        vector<int> lps(m);
        buildLps(lps, pat, m);
        
        vector<int> ans;
        
        int i = 0;
        int j = 0;
        while (i < n) {
            if (pat[j] == txt[i]) {
                i++;
                j++;
            } else {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
            
            if (j == m) {
                ans.push_back(i - j);
                j = lps[j - 1];
            }
        }
        
        return ans;
    }
};
