/*
 * @lc app=leetcode id=1171 lang=cpp
 *
 * [1171] Remove Zero Sum Consecutive Nodes from Linked List
 *
 * https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/description/
 *
 * algorithms
 * Medium (41.28%)
 * Likes:    440
 * Dislikes: 36
 * Total Accepted:    14.7K
 * Total Submissions: 35.7K
 * Testcase Example:  '[1,2,-3,3,1]'
 *
 * Given the head of a linked list, we repeatedly delete consecutive sequences
 * of nodes that sum to 0 until there are no such sequences.
 * 
 * After doing so, return the head of the final linked list.  You may return
 * any such answer.
 * 
 * 
 * (Note that in the examples below, all sequences are serializations of
 * ListNode objects.)
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,-3,3,1]
 * Output: [3,1]
 * Note: The answer [1,2,1] would also be accepted.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [1,2,3,-3,4]
 * Output: [1,2,4]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: head = [1,2,3,-3,-2]
 * Output: [1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The given linked list will contain between 1 and 1000 nodes.
 * Each node in the linked list has -1000 <= node.val <= 1000.
 * 
 * 
 */

// @lc code=start
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
    unordered_map<int, ListNode *> M;
    unordered_map<ListNode *, int> Ms;
    void remove(ListNode *front, ListNode *rear) {
        ListNode *curr = front->next;
        while (curr != rear) {
            M.erase(Ms[curr]);
            curr = curr -> next;
        }
        front->next = rear->next;
    }
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *curr = head, *tmp, *mhead = new ListNode(0, head);
        int sum = 0;
        M[sum] = mhead;
        while (curr != NULL) {
            sum += curr->val;
            if (M.count(sum)) {
                remove(M[sum], curr);
            } else {
                M[sum] = curr;
                Ms[curr] = sum;
            }
            curr = curr->next;
        }
        return mhead->next;
    }
};
// @lc code=end
