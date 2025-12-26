// Approach 1
// TC = O(n ^ 2)
// SC = O(1)
class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int minPenalty = INT_MAX;
        int minHour = INT_MAX;
        for (int i = 0; i <= n; i++) {
            int penalty = 0;
            for (int j = 0; j < n; j++) {
                if (j < i) {
                    penalty += (customers[j] == 'N') ? 1 : 0;
                } else {
                    penalty += (customers[j] == 'Y') ? 1 : 0;
                }
            }
            if (penalty < minPenalty) {
                minPenalty = penalty;
                minHour = i;
            }
        }
        return minHour;
    }
};

// Approach 2
// TC = O(3n)
// Sc = O(2n)
class Solution {
public:
    int bestClosingTime(string s) {
        int n = s.size();
        vector<int> prefixN(n + 1, 0);
        vector<int> suffixY(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == 'N')
                prefixN[i] = prefixN[i - 1] + 1;
            else
                prefixN[i] = prefixN[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            if(s[i] == 'Y')
                suffixY[i] = suffixY[i + 1] + 1;
            else
                suffixY[i] = suffixY[i + 1];
        }

        int minPenalty = INT_MAX;
        int minHour = INT_MAX;
        for (int i = 0; i <= n; i++) {
            int penalty = prefixN[i] + suffixY[i];
            if (penalty < minPenalty) {
                minHour = i;
                minPenalty = penalty;
            }
        }

        return minHour;
    }
};

// Approach 3
// TC = O(2n)
// SC = O(1)
class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int minPenalty = count(customers.begin(), customers.end(), 'Y');
        int minHour = 0;
        int penalty = minPenalty;
        for (int i = 1; i <= n; i++) {
            if (customers[i - 1] == 'Y') {
                penalty--;
            } else {
                penalty++;
            }
            
            if (penalty < minPenalty) {
                minPenalty = penalty;
                minHour = i;
            }
        }
        return minHour;
    }
};
