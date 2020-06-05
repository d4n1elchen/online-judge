/*
 * @lc app=leetcode id=959 lang=cpp
 *
 * [959] Regions Cut By Slashes
 *
 * https://leetcode.com/problems/regions-cut-by-slashes/description/
 *
 * algorithms
 * Medium (65.94%)
 * Likes:    709
 * Dislikes: 143
 * Total Accepted:    17K
 * Total Submissions: 25.8K
 * Testcase Example:  '[" /","/ "]'
 *
 * In a N x N grid composed of 1 x 1 squares, each 1 x 1 square consists of a
 * /, \, or blank space.  These characters divide the square into contiguous
 * regions.
 * 
 * (Note that backslash characters are escaped, so a \ is represented as
 * "\\".)
 * 
 * Return the number of regions.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * " /",
 * "/ "
 * ]
 * Output: 2
 * Explanation: The 2x2 grid is as follows:
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * [
 * " /",
 * "  "
 * ]
 * Output: 1
 * Explanation: The 2x2 grid is as follows:
 * 
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * [
 * "\\/",
 * "/\\"
 * ]
 * Output: 4
 * Explanation: (Recall that because \ characters are escaped, "\\/" refers to
 * \/, and "/\\" refers to /\.)
 * The 2x2 grid is as follows:
 * 
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input:
 * [
 * "/\\",
 * "\\/"
 * ]
 * Output: 5
 * Explanation: (Recall that because \ characters are escaped, "/\\" refers to
 * /\, and "\\/" refers to \/.)
 * The 2x2 grid is as follows:
 * 
 * 
 * 
 * 
 * Example 5:
 * 
 * 
 * Input:
 * [
 * "//",
 * "/ "
 * ]
 * Output: 3
 * Explanation: The 2x2 grid is as follows:
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= grid.length == grid[0].length <= 30
 * grid[i][j] is either '/', '\', or ' '.
 * 
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
private:
    int di[8] = {1, -1, 0,  0};
    int dj[8] = {0,  0, 1, -1};
    vector<vector<int>> color;
    int N, M;
    void dfs(int i, int j, int c, vector<string>& grid) {
        color[i][j] = c;
        for (int k=0; k<4; ++k) {
            int ni = i + di[k], nj = j + dj[k];
            if (ni >= 0 && ni < N*3 && nj >= 0 && nj < M*3 && !color[ni][nj]) {
                dfs(ni, nj, c, grid);
            }
        }
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        N = grid.size();
        M = grid[0].size();
        color = vector<vector<int>>(N * 3, vector<int>(M * 3, 0));

        for (int i=0; i<N; ++i) {
            for (int j=0; j<M; ++j) {
                if (grid[i][j] == '\\') {
                    color[3*i][3*j] = -1;
                    color[3*i+1][3*j+1] = -1;
                    color[3*i+2][3*j+2] = -1;
                } else if (grid[i][j] == '/') {
                    color[3*i+2][3*j] = -1;
                    color[3*i+1][3*j+1] = -1;
                    color[3*i][3*j+2] = -1;
                }
            }
        }

        int cur = 0;
        for (int i=0; i<N*3; ++i) {
            for (int j=0; j<M*3; ++j) {
                if (!color[i][j]) {
                    cur++;
                    dfs(i, j, cur, grid);
                }
            }
        }

        return cur;
    }
};
// @lc code=end
