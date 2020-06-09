/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (46.09%)
 * Likes:    5269
 * Dislikes: 191
 * Total Accepted:    700.8K
 * Total Submissions: 1.5M
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 * 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 * 
 * Output: 3
 * 
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> color;
    int N, M;
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    void dfs(int r, int c, int n, vector<vector<char>> &grid) {
        color[r][c] = n;
        for (int i=0; i<4; ++i) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < N && nc >= 0 && nc < M && color[nr][nc] == -1 && grid[nr][nc] == '1') dfs(nr, nc, n, grid);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        N = grid.size(); 
        if (N == 0) return 0;
        M = grid[0].size();
        if (M == 0) return 0;

        color = vector<vector<int>>(N, vector<int>(M, -1));
        int c = 0;
        for (int i=0; i<N; ++i) {
            for (int j=0; j<M; ++j) {
                if (color[i][j] == -1 && grid[i][j] == '1') dfs(i, j, c++, grid);
            }
        }
        return c;
    }
};
// @lc code=end
