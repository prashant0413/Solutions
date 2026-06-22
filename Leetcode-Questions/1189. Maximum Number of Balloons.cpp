// Approach 1
// TC = O(N)
// SC = O(1)
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int freq[26] = {0};
        for (char &t: text) {
            freq[t - 'a']++;
        }

        int cnt = INT_MAX;
        for (int i = 0; i < 26; i++) {
            if (i == 0) {
                cnt = min(freq[i], cnt);
            }

            if (i == ('b' - 'a')) {
                cnt = min(freq[i], cnt);
            }

            if (i == ('l' - 'a')) {
                cnt = min(freq[i] / 2, cnt);
            }

            if (i == ('n' - 'a')) {
                cnt = min(freq[i], cnt);
            }

            if (i == ('o' - 'a')) {
                cnt = min(freq[i] / 2, cnt);
            }
        }
        return cnt;
    }
};
