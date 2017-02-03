/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
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
