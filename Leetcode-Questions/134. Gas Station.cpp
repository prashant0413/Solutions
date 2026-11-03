// APPROACH 1: BRUTE FORCE
// TC: O(N^2)
// SC: O(1)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for (int k = 0; k < n; k++) {
            int petrol = 0;
            int i = k;
            while (true) {
                petrol += gas[i % n];
                petrol -= cost[i % n];
                if (petrol < 0) break;

                i = i + 1;
                if ((i % n) == k) return k;
            }
        }

        return -1;
    }
};

// APPROACH 2: GREEDY
// TC: O(N)
// SC: O(1)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int kamai = accumulate(begin(gas), end(gas), 0);
        int kharch = accumulate(begin(cost), end(cost), 0);
        if (kamai < kharch) return -1;

        int res = 0;
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += gas[i] - cost[i];
            if (total < 0) {
                res = i + 1;
                total = 0;
            }
        }

        return res;
    }
};
