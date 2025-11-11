// 1. Brute Force
// TIme Complexity = O(max(num1, num2))

class Solution
{
public:
    int countOperations(int num1, int num2)
    {
        int cnt = 0;
        while (num1 && num2)
        {
            if (num1 >= num2)
                num1 -= num2;
            else
                num2 -= num1;
            cnt++;
        }
        return cnt;
    }
};

// 2. Euclidean Algorithm
// Time Complexity = O(log(min(num1, num2)))

class Solution
{
public:
    int countOperations(int num1, int num2)
    {
        int cnt = 0;
        while (num1 && num2) {
            cnt += num1 / num2;
            num1 = num1 % num2;
            swap(num1, num2);
        }
        return cnt;
    }
};
