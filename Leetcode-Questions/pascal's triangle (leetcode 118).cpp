class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res;
        for (int i = 1; i <= numRows; i++)
        {
            res.push_back(generateRow(i));
        }
        return res;
    }
    vector<int> generateRow(int row)
    {
        long long ans = 1;
        vector<int> res;
        res.push_back(1);

        for (int col = 1; col < row; col++)
        {
            ans = ans * (row - col);
            ans = ans / col;
            res.push_back(ans);
        }
        return res;
    }
};
