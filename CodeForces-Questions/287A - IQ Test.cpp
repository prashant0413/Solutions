#include <bits/stdc++.h>
using namespace std;

bool checkRight(int i, int j, vector<vector<char>> &arr)
{
    if (j == 0 || i == 3)
        return false;
    char c = arr[i][j - 1];
    if (arr[i + 1][j - 1] == c && arr[i + 1][j] == c)
        return true;
    return false;
}

bool checkLeft(int i, int j, vector<vector<char>> &arr)
{
    if (j == 3 || i == 3)
        return false;
    char c = arr[i][j + 1];
    if (arr[i + 1][j + 1] == c && arr[i + 1][j] == c)
        return true;
    return false;
}

bool upRight(int i, int j, vector<vector<char>> &arr)
{
    if (j == 0 || i == 0)
        return false;
    char c = arr[i][j - 1];
    if (arr[i - 1][j - 1] == c && arr[i - 1][j] == c)
        return true;
    return false;
}

bool upLeft(int i, int j, vector<vector<char>> &arr)
{
    if (j == 0 || i == 0)
        return false;
    char c = arr[i][j + 1];
    if (arr[i - 1][j + 1] == c && arr[i - 1][j] == c)
        return true;
    return false;
}

int main()
{
    vector<vector<char>> arr(4, vector<char>(4));
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            cin >> arr[i][j];
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (checkLeft(i, j, arr) || checkRight(i, j, arr) || upLeft(i, j, arr) || upRight(i, j, arr)) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;
    return 0;
}
