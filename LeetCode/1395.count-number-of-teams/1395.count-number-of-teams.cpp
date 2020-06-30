/*
 * @lc app=leetcode id=1395 lang=cpp
 *
 * [1395] Count Number of Teams
 *
 * https://leetcode.com/problems/count-number-of-teams/description/
 *
 * algorithms
 * Medium (81.16%)
 * Likes:    294
 * Dislikes: 66
 * Total Accepted:    20.7K
 * Total Submissions: 25.6K
 * Testcase Example:  '[2,5,3,4,1]\r'
 *
 * There are n soldiers standing in a line. Each soldier is assigned a unique
 * rating value.
 * 
 * You have to form a team of 3 soldiers amongst them under the following
 * rules:
 * 
 * 
 * Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j],
 * rating[k]).
 * A team is valid if:  (rating[i] < rating[j] < rating[k]) or (rating[i] >
 * rating[j] > rating[k]) where (0 <= i < j < k < n).
 * 
 * 
 * Return the number of teams you can form given the conditions. (soldiers can
 * be part of multiple teams).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: rating = [2,5,3,4,1]
 * Output: 3
 * Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1),
 * (5,3,1). 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: rating = [2,1,3]
 * Output: 0
 * Explanation: We can't form any team given the conditions.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: rating = [1,2,3,4]
 * Output: 4
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == rating.length
 * 1 <= n <= 200
 * 1 <= rating[i] <= 10^5
 * 
 */

// @lc code=start
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int cnt = 0, N = rating.size();
        for (int i=0; i<N; ++i) {
            int left[2] = {0, 0}, right[2] = {0, 0};
            for (int j=0; j<i; ++j) {
                if (rating[j] < rating[i]) left[0]++;
                else if (rating[j] > rating[i]) left[1]++;
            }
            for (int j=i+1; j<N; ++j) {
                if (rating[j] < rating[i]) right[0]++;
                else if (rating[j] > rating[i]) right[1]++;
            }
            cnt += left[0] * right[1] + left[1] * right[0];
        }
        return cnt;
    }
};
// @lc code=end
