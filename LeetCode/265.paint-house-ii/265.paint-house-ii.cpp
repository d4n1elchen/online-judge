/*
 * @lc app=leetcode id=265 lang=cpp
 *
 * [265] Paint House II
 *
 * https://leetcode.com/problems/paint-house-ii/description/
 *
 * algorithms
 * Hard (44.20%)
 * Likes:    506
 * Dislikes: 18
 * Total Accepted:    58.8K
 * Total Submissions: 132.6K
 * Testcase Example:  '[[1,5,3],[2,9,4]]'
 *
 * There are a row of n houses, each house can be painted with one of the k
 * colors. The cost of painting each house with a certain color is different.
 * You have to paint all the houses such that no two adjacent houses have the
 * same color.
 * 
 * The cost of painting each house with a certain color is represented by a n x
 * k cost matrix. For example, costs[0][0] is the cost of painting house 0 with
 * color 0; costs[1][2] is the cost of painting house 1 with color 2, and so
 * on... Find the minimum cost to paint all houses.
 * 
 * Note:
 * All costs are positive integers.
 * 
 * Example:
 * 
 * 
 * Input: [[1,5,3],[2,9,4]]
 * Output: 5
 * Explanation: Paint house 0 into color 0, paint house 1 into color 2. Minimum
 * cost: 1 + 4 = 5; 
 * Or paint house 0 into color 2, paint house 1 into color 0. Minimum cost: 3 +
 * 2 = 5. 
 * 
 * 
 * Follow up:
 * Could you solve it in O(nk) runtime?
 * 
 */

// @lc code=start
#define INF 2e9
class Solution {
private:
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.size() == 0 || costs[0].size() == 0) return 0;
        int N = costs.size(), K = costs[0].size();
        vector<vector<int>> dp(2, vector<int>(K, INF));
        dp[0] = costs[0];
        for (int i=1; i<N; ++i) {
            int mi = 0, mi2 = -1;
            for (int j=1; j<K; ++j) {
                if (dp[0][j] < dp[0][mi]) {
                    mi2 = mi;
                    mi = j;
                } else if (mi2 == -1 || dp[0][j] < dp[0][mi2]) {
                    mi2 = j;
                }
            }
            for (int j=0; j<K; ++j) {
                if (j != mi)
                    dp[1][j] = dp[0][mi] + costs[i][j];
                else
                    dp[1][j] = dp[0][mi2] + costs[i][j];
            }
            dp[0] = dp[1];
        }
        int res = INF;
        for (auto v : dp[0]) res = min(res, v);
        return res;
    }
};
// @lc code=end
