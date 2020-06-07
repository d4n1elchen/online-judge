/*
 * @lc app=leetcode id=256 lang=cpp
 *
 * [256] Paint House
 *
 * https://leetcode.com/problems/paint-house/description/
 *
 * algorithms
 * Easy (51.71%)
 * Likes:    771
 * Dislikes: 80
 * Total Accepted:    83.7K
 * Total Submissions: 161.8K
 * Testcase Example:  '[[17,2,17],[16,16,5],[14,3,19]]'
 *
 * There are a row of n houses, each house can be painted with one of the three
 * colors: red, blue or green. The cost of painting each house with a certain
 * color is different. You have to paint all the houses such that no two
 * adjacent houses have the same color.
 * 
 * The cost of painting each house with a certain color is represented by a n x
 * 3 cost matrix. For example, costs[0][0] is the cost of painting house 0 with
 * color red; costs[1][2] is the cost of painting house 1 with color green, and
 * so on... Find the minimum cost to paint all houses.
 * 
 * Note:
 * All costs are positive integers.
 * 
 * Example:
 * 
 * 
 * Input: [[17,2,17],[16,16,5],[14,3,19]]
 * Output: 10
 * Explanation: Paint house 0 into blue, paint house 1 into green, paint house
 * 2 into blue. 
 * Minimum cost: 2 + 5 + 3 = 10.
 * 
 * 
 */

// @lc code=start
#define INF 1e9
class Solution {
private:
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.size() == 0) return 0;
        int N = costs.size();
        vector<vector<int>> dp(N, vector<int>(3, INF));
        dp[0] = costs[0];
        for (int i=1; i<N; ++i) {
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + costs[i][0];
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + costs[i][1];
            dp[i][2] = min(dp[i-1][1], dp[i-1][0]) + costs[i][2];
        }
        return min({dp[N-1][0], dp[N-1][1], dp[N-1][2]});
    }
};
// @lc code=end
