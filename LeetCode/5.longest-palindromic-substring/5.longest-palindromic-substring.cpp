/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (29.16%)
 * Likes:    6691
 * Dislikes: 528
 * Total Accepted:    923.6K
 * Total Submissions: 3.2M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int N = s.size();
        if (N < 2) return s;
        vector<vector<bool>> dp(2, vector<bool>(N, false));
        int len = 1, start = 0;
        for (int i=0; i<N; ++i) {
            dp[0][i] = true;
            if (i+1 < N && s[i] == s[i+1]) {
                dp[1][i] = true;
                if (len == 1) start = i, len = 2;
            }
        }
        for (int i=2; i<N; ++i) {
            int parity = i & 1;
            for (int j=0; j<N-i; ++j) {
                if (s[j] == s[j+i] && dp[parity][j+1]) {
                    dp[parity][j] = true;
                    if (i + 1 > len) start = j, len = i + 1;
                } else {
                    dp[parity][j] = false;
                }
            }
        }
        return s.substr(start, len);
    }
};
// @lc code=end
