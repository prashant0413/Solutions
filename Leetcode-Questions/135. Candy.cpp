// Approach 1
// TC: O(3n)
// SC: O(2n)
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n, 0), right(n, 0);
        left[0] = 1;
        right[n - 1] = 1;

        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            } else {
                left[i] = 1;
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                right[i] = right[i + 1] + 1;
            } else {
                right[i] = 1;
            }
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += max(left[i], right[i]);
        }

        return sum;
    }
};

// Approach 2
// TC: O(2n)
// SC: O(n)
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n, 0);
        left[0] = 1;

        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            } else {
                left[i] = 1;
            }
        }

        int sum = max(left[n - 1], 1);
        int curr = 1;
        int right = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                curr = right + 1;
                right = curr;
            } else {
                curr = 1;
                right = curr;
            }
            sum += max(left[i], curr);
        }

        return sum;
    }
};
