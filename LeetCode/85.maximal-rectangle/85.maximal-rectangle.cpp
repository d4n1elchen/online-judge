/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 *
 * https://leetcode.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (36.88%)
 * Likes:    2667
 * Dislikes: 67
 * Total Accepted:    173.1K
 * Total Submissions: 466.1K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
 * containing only 1's and return its area.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * ⁠ ["1","0","1","0","0"],
 * ⁠ ["1","0","1","1","1"],
 * ⁠ ["1","1","1","1","1"],
 * ⁠ ["1","0","0","1","0"]
 * ]
 * Output: 6
 * 
 * 
 */

// @lc code=start
class Solution {
private:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() == 0) return 0;
        int N = heights.size();
        stack<int> st;
        st.push(-1);
        int ma = 0;
        for (int i=0; i<N; ++i) {
            while (st.top() != -1 && heights[i] < heights[st.top()]) {
                int j = st.top(); st.pop();
                ma = max(ma, heights[j] * (i - st.top() - 1));
            }
            st.push(i);
        }
        while (st.top() != -1) {
            int j = st.top(); st.pop();
            ma = max(ma, heights[j] * (N - st.top() - 1));
        }
        return ma;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int N = matrix.size(), M = matrix[0].size();
        vector<int> heights(M, 0);
        int ma = 0;
        for (int i=0; i<N; ++i) {
            for (int j=0; j<M; ++j) {
                heights[j] = matrix[i][j] == '1' ? heights[j] + 1 : 0;
            }
            ma = max(ma, largestRectangleArea(heights));
        }
        return ma;
    }
};
// @lc code=end
