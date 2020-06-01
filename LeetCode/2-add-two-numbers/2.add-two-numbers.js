/*
 * @lc app=leetcode id=2 lang=javascript
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (33.37%)
 * Total Accepted:    1.4M
 * Total Submissions: 4.1M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example:
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    var r = new ListNode(0);
    var result = r;
    while(l1 !== null && l2 !== null) {
        if(result.next !== null)
            result = result.next;
        result.val = result.val + l1.val + l2.val;
        result.next = new ListNode(Math.floor(result.val/10));
        result.val = result.val%10;
        l1 = l1.next;
        l2 = l2.next;
    }
    while(l1 !== null) {
        result = result.next;
        result.val = result.val + l1.val;
        result.next = new ListNode(Math.floor(result.val/10));
        result.val = result.val%10;
        l1 = l1.next;
    }
    while(l2 !== null) {
        result = result.next;
        result.val = result.val + l2.val;
        result.next = new ListNode(Math.floor(result.val/10));
        result.val = result.val%10;
        l2 = l2.next;
    }
    if(result.next.val === 0) result.next = null;
    return r;
};
