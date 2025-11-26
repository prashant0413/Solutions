class Solution {
    void solve(int i, int j, vector<vector<int>>& maze, vector<string>& ans, string s, vector<vector<int>>& vis, vector<int>& di, vector<int>& dj, int n) {
        if (i == n - 1 && j == n - 1) {
            ans.push_back(s);
            return;
        }
        string dir = "DLRU";
        for (int index = 0; index < 4; index++) {
            int nexti = i + di[index];
            int nextj = j + dj[index];
            if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && maze[nexti][nextj] == 1) {
                vis[i][j] = 1;
                solve(nexti, nextj, maze, ans, s + dir[index], vis, di, dj, n);
                vis[i][j] = 0;
            }
        }
        
    }
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string> ans;
        vector<int> di = {1, 0, 0, -1};
        vector<int> dj = {0, -1, 1, 0};
        vector<vector<int>> vis(n, vector<int>(n, 0));
        if (maze[0][0] == 1)
            solve(0, 0, maze, ans, "", vis, di, dj, n);
        return ans;
    }
};
