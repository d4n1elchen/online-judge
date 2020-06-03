/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.82%)
 * Likes:    1961
 * Dislikes: 135
 * Total Accepted:    459.3K
 * Total Submissions: 1M
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [-1,2,1,-4], target = 1
 * Output: 2
 * Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 =
 * 2).
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 3 <= nums.length <= 10^3
 * -10^3 <= nums[i] <= 10^3
 * -10^4 <= target <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int N = nums.size();

        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2];
        for (int i=0; i<N; ++i) {
            int nt = target - nums[i];
            int L = 0, R = N-1;
            while (L < R) {
                if (R==i) {
                    R--; continue;
                } else if (L==i) {
                    L++; continue;
                }

                if (abs(nums[L] + nums[R] + nums[i] - target) < abs(closest - target)) closest = nums[L] + nums[R] + nums[i];

                if (nums[L] + nums[R] == nt) return target;
                else if (nums[L] + nums[R] > nt) {
                    R--;
                } else {
                    L++;
                }
            }
        }
        return closest;
    }
};
// @lc code=end
