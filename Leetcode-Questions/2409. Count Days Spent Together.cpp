// APPROACH 1:
// TC: O(1)
// SC: O(1)
class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for (int i = 1; i <= 12; i++) {
            days[i] = days[i] + days[i - 1];
        }

        int monthArrive1 = stoi(arriveAlice.substr(0, 2));
        int monthLeave1 = stoi(leaveAlice.substr(0, 2));
        int dayArrive1 = stoi(arriveAlice.substr(3, 2));
        int dayLeave1 = stoi(leaveAlice.substr(3, 2));

        int monthArrive2 = stoi(arriveBob.substr(0, 2));
        int monthLeave2 = stoi(leaveBob.substr(0, 2));
        int dayArrive2 = stoi(arriveBob.substr(3, 2));
        int dayLeave2 = stoi(leaveBob.substr(3, 2));

        int startAlice = days[monthArrive1 - 1] + dayArrive1;
        int endAlice = days[monthLeave1 - 1] + dayLeave1;

        int startBob = days[monthArrive2 - 1] + dayArrive2;
        int endBob = days[monthLeave2 - 1] + dayLeave2;

        int start = max(startBob, startAlice);
        int end = min(endBob, endAlice);

        return start > end ? 0 : end - start + 1;
    }
};
