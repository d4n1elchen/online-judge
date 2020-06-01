/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 *
 * https://leetcode.com/problems/first-bad-version/description/
 *
 * algorithms
 * Easy (34.89%)
 * Total Accepted:    405.5K
 * Total Submissions: 1.2M
 * Testcase Example:  '5\n4'
 *
 * You are a product manager and currently leading a team to develop a new
 * product. Unfortunately, the latest version of your product fails the quality
 * check. Since each version is developed based on the previous version, all
 * the versions after a bad version are also bad.
 * 
 * Suppose you have n versions [1, 2, ..., n] and you want to find out the
 * first bad one, which causes all the following ones to be bad.
 * 
 * You are given an API bool isBadVersion(version) which will return whether
 * version is bad. Implement a function to find the first bad version. You
 * should minimize the number of calls to the API.
 * 
 * Example:
 * 
 * 
 * Given n = 5, and version = 4 is the first bad version.
 * 
 * call isBadVersion(3) -> false
 * call isBadVersion(5) -> true
 * call isBadVersion(4) -> true
 * 
 * Then 4 is the first bad version. 
 * 
 * 
 */
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int a = 1, b = n;
        bool bn, bn1;
        n = a+(b-a)/2;
        while(a <= b) {
            bn = isBadVersion(n);
            bn1 = isBadVersion(n-1);
            if(bn && !bn1) break;
            if(bn)
            b = n - 1;
            else
            a = n + 1;
            n = a+(b-a)/2;
        }
        return n;
    }
};
