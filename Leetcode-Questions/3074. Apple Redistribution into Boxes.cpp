// Approach 1
// TC = O(nlog(n)) + O(n + m);
// SC = O(1)
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApples = 0;
        for (int &i : apple)
            totalApples += i;
        int boxes = 0;
        sort(capacity.begin(), capacity.end(), greater<int>());
        for (int &i : capacity) {
            if (totalApples <= 0)
                break;
            totalApples -= i;
            boxes++;
        }
        return boxes;
    }
};
