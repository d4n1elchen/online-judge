/*
 * @lc app=leetcode id=632 lang=cpp
 *
 * [632] Smallest Range Covering Elements from K Lists
 *
 * https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/
 *
 * algorithms
 * Hard (51.72%)
 * Likes:    1009
 * Dislikes: 24
 * Total Accepted:    36.4K
 * Total Submissions: 70.3K
 * Testcase Example:  '[[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]'
 *
 * You have k lists of sorted integers in ascending order. Find the smallest
 * range that includes at least one number from each of the k lists.
 * 
 * We define the range [a,b] is smaller than range [c,d] if b-a < d-c or a < c
 * if b-a == d-c.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
 * Output: [20,24]
 * Explanation: 
 * List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
 * List 2: [0, 9, 12, 20], 20 is in range [20,24].
 * List 3: [5, 18, 22, 30], 22 is in range [20,24].
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The given list may contain duplicates, so ascending order means >= here.
 * 1 <= k <= 3500
 * -10^5 <= value of elements <= 10^5.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int N = nums.size();
        vector<int> next(N, 0);
        auto comp = [&](int &a, int &b) {
            return nums[a][next[a]] > nums[b][next[b]];
        };
        priority_queue<int, vector<int>, decltype(comp)> PQ(comp);
        int l = nums[0][0], r = nums[0][0], rr = nums[0][0];
        for (int i=0; i<N; ++i) {
            PQ.push(i);
            l = min(l, nums[i][0]);
            r = max(r, nums[i][0]);
            rr = max(rr, nums[i][0]);
        }
        while (!PQ.empty()) {
            int min_i = PQ.top(); PQ.pop();
            if (r - l > rr - nums[min_i][next[min_i]]) l = nums[min_i][next[min_i]], r = rr;
            next[min_i]++;
            if (next[min_i] == nums[min_i].size()) break;
            PQ.push(min_i);
            rr = max(rr, nums[min_i][next[min_i]]);
        }
        return vector<int>{l, r};
    }
};
// @lc code=end
