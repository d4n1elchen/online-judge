/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (34.32%)
 * Likes:    3370
 * Dislikes: 78
 * Total Accepted:    250.4K
 * Total Submissions: 728.7K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * Given n non-negative integers representing the histogram's bar height where
 * the width of each bar is 1, find the area of largest rectangle in the
 * histogram.
 * 
 * 
 * 
 * 
 * Above is a histogram where width of each bar is 1, given height =
 * [2,1,5,6,2,3].
 * 
 * 
 * 
 * 
 * The largest rectangle is shown in the shaded area, which has area = 10
 * unit.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [2,1,5,6,2,3]
 * Output: 10
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int N = heights.size();
        vector<int> left(N, 0), right(N, 0);

        for (int i=0; i<N; ++i) {
            int p = i;
            while (p-1 >= 0 && heights[p-1] >= heights[i]) p = left[p-1];
            left[i] = p;
        }
        for (int i=N-1; i>=0; --i) {
            int p = i+1;
            while (p < N && heights[p] >= heights[i]) p = right[p];
            right[i] = p;
        }
        int ans = 0;
        for (int i=0; i<N; ++i) {
            ans = max(ans, heights[i] * (right[i] - left[i]));
        }
        return ans;
    }
};
// @lc code=end
