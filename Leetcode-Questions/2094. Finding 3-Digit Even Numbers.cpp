// Approach 1
// TC = O(N)
// SC = O(1)
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int freq[10] = {0};
        for (int i: digits) {
            freq[i]++;
        }

        vector<int> ans;
        for (int h = 1; h <= 9; h++) {
            if (freq[h] == 0) continue;
            freq[h]--;
            for (int t = 0; t <= 9; t++) {
                if (freq[t] == 0) continue;
                freq[t]--;
                for (int o = 0; o <= 8; o += 2) {
                    if (freq[o] == 0) continue;
                    int num = h * 100 + t * 10 + o;
                    ans.push_back(num);
                }
                freq[t]++;
            }
            freq[h]++;
        }

        return ans;
    }
};
