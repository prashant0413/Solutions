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
