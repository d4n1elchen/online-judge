/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (45.40%)
 * Total Accepted:    2.9M
 * Total Submissions: 6.4M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * Example:
 * 
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 * 
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> table;
        vector<int> result;
        vector<int>::iterator it = nums.begin();
        for(; it != nums.end(); ++it) {
        int index = it-nums.begin();
        int num = *it;
        int remain = target - num;
            if(table.find(num) != table.end()) {
                result.push_back(table[num]);
                result.push_back(index);
                break;
            } else {
                table[remain] = index;
            }
        }
        return result;
    }
};
