/*
 * @lc app=leetcode id=2 lang=cpp
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
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* r = new ListNode(0);
        ListNode* result = r;
        while(l1 != NULL && l2 != NULL) {
            if(result->next != NULL)
                result = result->next;
            result->val = result->val + l1->val + l2->val;
            result->next = new ListNode(result->val/10);
            result->val = result->val%10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL) {
            result = result->next;
            result->val = result->val + l1->val;
            result->next = new ListNode(result->val/10);
            result->val = result->val%10;
            l1 = l1->next;
        }
        while(l2 != NULL) {
            result = result->next;
            result->val = result->val + l2->val;
            result->next = new ListNode(result->val/10);
            result->val = result->val%10;
            l2 = l2->next;
        }
        if(result->next->val == 0) {
            result->next = NULL;
        }
        return r;
    }
};
