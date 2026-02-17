// Approach 1
// TC = O(1)
// SC = O(1)

// note
// "__builtin_popcount" is function for counting set bits
// it is faster than custom made
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        for (int hour = 0; hour < 12; hour++) {
            for (int minute = 0; minute < 60; minute++) {
                if (__builtin_popcount(hour) + __builtin_popcount(minute) == turnedOn) {
                    string h = to_string(hour);
                    string m = ((minute < 10) ? "0" : "") + to_string(minute);

                    res.push_back(h + ":" + m);
                }
            }
        }
        return res;
    }
};
