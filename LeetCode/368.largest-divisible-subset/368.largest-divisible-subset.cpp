/*
 * @lc app=leetcode id=368 lang=cpp
 *
 * [368] Largest Divisible Subset
 *
 * https://leetcode.com/problems/largest-divisible-subset/description/
 *
 * algorithms
 * Medium (36.34%)
 * Likes:    1266
 * Dislikes: 61
 * Total Accepted:    88.9K
 * Total Submissions: 234.4K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct positive integers, find the largest subset such that
 * every pair (Si, Sj) of elements in this subset satisfies:
 * 
 * Si % Sj = 0 or Sj % Si = 0.
 * 
 * If there are multiple solutions, return any subset is fine.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: [1,2,3]
 * Output: [1,2] (of course, [1,3] will also be ok)
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,4,8]
 * Output: [1,2,4,8]
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int N = nums.size();
        vector<vector<int>> dp(N, vector<int>());
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for (int i=0; i<N; ++i) {
            for (int j=i-1; j>=0; --j) {
                if (nums[i] % nums[j] == 0 && dp[j].size() > dp[i].size()) {
                    dp[i] = dp[j];
                }
            }
            dp[i].push_back(nums[i]);
            if (dp[i].size() > ans.size()) ans = dp[i];
        }
        return ans;
    }
};
// @lc code=end
