/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 *
 * https://leetcode.com/problems/decode-string/description/
 *
 * algorithms
 * Medium (49.01%)
 * Likes:    3058
 * Dislikes: 158
 * Total Accepted:    202.5K
 * Total Submissions: 410K
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * Given an encoded string, return its decoded string.
 * 
 * The encoding rule is: k[encoded_string], where the encoded_string inside the
 * square brackets is being repeated exactly k times. Note that k is guaranteed
 * to be a positive integer.
 * 
 * You may assume that the input string is always valid; No extra white spaces,
 * square brackets are well-formed, etc.
 * 
 * Furthermore, you may assume that the original data does not contain any
 * digits and that digits are only for those repeat numbers, k. For example,
 * there won't be input like 3a or 2[4].
 * 
 * 
 * Example 1:
 * Input: s = "3[a]2[bc]"
 * Output: "aaabcbc"
 * Example 2:
 * Input: s = "3[a2[c]]"
 * Output: "accaccacc"
 * Example 3:
 * Input: s = "2[abc]3[cd]ef"
 * Output: "abcabccdcdcdef"
 * Example 4:
 * Input: s = "abc3[cd]xyz"
 * Output: "abccdcdcdxyz"
 * 
 */

// @lc code=start
class Solution {
private:
    bool isNum(char c) {
        return c >= '0' && c <= '9';
    }
public:
    string decodeString(string s) {
        string ss;
        for (int i=0; i<s.size(); ++i) {
            if (isNum(s[i])) {
                int nst, len, cnt;
                for (nst=i, len=1; i+len<s.size() && s[i+len] != '['; ++len) ;
                int n = stol(s.substr(nst, len));
                i = i + len + 1;
                cnt = 1;
                for (nst=i, len=1; i+len<s.size(); ++len) {
                    if (s[i+len] == '[') cnt++;
                    else if (s[i+len] == ']') cnt--;
                    if (cnt == 0) break;
                }
                string ts = decodeString(s.substr(nst, len));
                for (int j=0; j<n; ++j) ss += ts;
                i = i + len;
            } else {
                ss += s[i];
            }
        }
        return ss;
    }
};
// @lc code=end
