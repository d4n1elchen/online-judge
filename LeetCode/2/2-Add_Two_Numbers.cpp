/**
 * Definition for singly-linked list->
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
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
