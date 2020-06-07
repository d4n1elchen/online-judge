/*
 * @lc app=leetcode id=886 lang=cpp
 *
 * [886] Possible Bipartition
 *
 * https://leetcode.com/problems/possible-bipartition/description/
 *
 * algorithms
 * Medium (43.52%)
 * Likes:    862
 * Dislikes: 27
 * Total Accepted:    51.9K
 * Total Submissions: 119K
 * Testcase Example:  '4\n[[1,2],[1,3],[2,4]]'
 *
 * Given a set of N people (numbered 1, 2, ..., N), we would like to split
 * everyone into two groups of any size.
 * 
 * Each person may dislike some other people, and they should not go into the
 * same group. 
 * 
 * Formally, if dislikes[i] = [a, b], it means it is not allowed to put the
 * people numbered a and b into the same group.
 * 
 * Return true if and only if it is possible to split everyone into two groups
 * in this way.
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
 * Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
 * Output: true
 * Explanation: group1 [1,4], group2 [2,3]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
 * Output: false
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
 * Output: false
 * 
 * 
 * 
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= N <= 2000
 * 0 <= dislikes.length <= 10000
 * dislikes[i].length == 2
 * 1 <= dislikes[i][j] <= N
 * dislikes[i][0] < dislikes[i][1]
 * There does not exist i != j for which dislikes[i] == dislikes[j].
 * 
 * 
 */

// @lc code=start
class Solution {
private:
    unordered_map<int, vector<int>> adj;
    vector<int> visited;
    bool dfs(int n, int v) {
        visited[n] = v;
        for (int q : adj[n]) {
            if (visited[q] == -1) {
                if (!dfs(q, v^1))
                    return false;
            } else if (visited[q] == v) {
                return false;
            }
        }
        return true;
    }
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        for (auto d : dislikes) {
            adj[d[0]-1].push_back(d[1]-1);
            adj[d[1]-1].push_back(d[0]-1);
        }
        visited = vector<int>(N, -1);
        for (int i=0; i<N; ++i) {
            if (visited[i] == -1 && !dfs(i, 1)) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
