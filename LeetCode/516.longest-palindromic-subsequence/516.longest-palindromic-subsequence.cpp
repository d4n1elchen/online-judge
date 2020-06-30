/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 *
 * https://leetcode.com/problems/longest-palindromic-subsequence/description/
 *
 * algorithms
 * Medium (51.97%)
 * Likes:    1885
 * Dislikes: 172
 * Total Accepted:    114.7K
 * Total Submissions: 218.6K
 * Testcase Example:  '"bbbab"'
 *
 * Given a string s, find the longest palindromic subsequence's length in s.
 * You may assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * Input:
 * 
 * 
 * "bbbab"
 * 
 * Output:
 * 
 * 
 * 4
 * 
 * One possible longest palindromic subsequence is "bbbb".
 * 
 * 
 * 
 * Example 2:
 * Input:
 * 
 * 
 * "cbbd"
 * 
 * Output:
 * 
 * 
 * 2
 * 
 * One possible longest palindromic subsequence is "bb".
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 1000
 * s consists only of lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if (s.size() <= 1) return s.size();
        int N = s.size();
        vector<vector<int>> dp(N+1, vector<int>(N+1, 0));

        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                dp[i+1][j+1] = max({dp[i][j] + (s[i] == s[N-j-1]), dp[i][j+1], dp[i+1][j]});
            }
        }

        return dp[N][N];
    }
};
// @lc code=end
