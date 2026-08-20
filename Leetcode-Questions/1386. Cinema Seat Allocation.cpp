// Approach 1
// TC = O(reservedSeats)
// SC = O(reservedSeats)
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> mpp;
        for (auto it: reservedSeats) {
            mpp[it[0]].insert(it[1]);
        }

        int result = 0;
        result += (n - mpp.size()) * 2;
        for (auto &[row, bookedSeats]: mpp) {
            auto isAvailable = [&](int seat) {
                return bookedSeats.count(seat) == 0;
            };

            bool groupA = isAvailable(2) && isAvailable(3) && isAvailable(4) && isAvailable(5);
            bool groupB = isAvailable(4) && isAvailable(5) && isAvailable(6) && isAvailable(7);
            bool groupC = isAvailable(6) && isAvailable(7) && isAvailable(8) && isAvailable(9);

            if (groupA && groupC)
                result += 2;
            else if (groupA || groupB || groupC)
                result++;
        }
        return result;
    }
};

// Approach 2
// TC = O(reservedSeats)
// SC = O(1)
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mpp;
        for (auto it: reservedSeats) {
            mpp[it[0]] |= (1 << it[1]);
        }

        int result = (n - mpp.size()) * 2;
        int groupAMask = 0b111100;
        int groupBMask = 0b11110000;
        int groupCMask = 0b1111000000;

        for (auto& [row, seats]: mpp) {
            bool groupA = (seats & groupAMask) == 0;
            bool groupB = (seats & groupBMask) == 0;
            bool groupC = (seats & groupCMask) == 0;

            if (groupA && groupC)
                result += 2;
            else if (groupA || groupB || groupC)
                result++;
        }
        return result;
    }
};
