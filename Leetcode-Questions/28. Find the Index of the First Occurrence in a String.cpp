// APPROACH 1: KMP ALGORITHM OF STRING MATCHING
// TC: O(N + M)
// SC: O(M)
class Solution {
private:
    void buildLps(string &needle, vector<int> &LPS, int M) {
        int i = 1;
        int len = 0;
        LPS[0] = 0;
        while (i < M) {
            if (needle[i] == needle[len]) {
                len++;
                LPS[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = LPS[len - 1];
                } else {
                    LPS[i] = 0;
                    i++;
                }
            }
        }
    }
public:
    int strStr(string haystack, string needle) {
        int N = haystack.size();
        int M = needle.size();

        vector<int> LPS(M);
        buildLps(needle, LPS, M);

        int i = 0;
        int j = 0;
        while (i < N) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                if (j != 0) {
                    j = LPS[j - 1];
                } else {
                    i++;
                }
            }

            if (j == M) return i - j;
        }

        return -1;
    }
};

// APPROACH 2: USING BUILT IN FUNCTION
// TC: O(N . M)
// SC: O(1)
class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};
