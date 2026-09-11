// Approach 1
// TC = O(N^3)
// SC = O(K)
class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();

        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            if (digits[i] == 0) continue;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                for (int k = 0; k < n; k++) {
                    if (i == k || k == j) continue;
                    if (digits[k] & 1) continue;
                    int num = digits[i] * 10 + digits[j];
                    num = num * 10 + digits[k];
                    st.insert(num);
                }
            }
        }

        return st.size();
    }
};

// Approach 2
// TC = O(N)
// SC = O(1)
class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10] = {0};
        for (int i: digits) {
            freq[i]++;
        }

        int cnt = 0;
        for (int h = 1; h <= 9; h++) {
            if (freq[h] == 0) continue;
            freq[h]--;
            for (int t = 0; t <= 9; t++) {
                if (freq[t] == 0) continue;
                freq[t]--;
                for (int o = 0; o <= 8; o += 2) {
                    if (freq[o] == 0) continue;
                    cnt++;
                }
                freq[t]++;
            }
            freq[h]++;
        }

        return cnt;
    }
};
