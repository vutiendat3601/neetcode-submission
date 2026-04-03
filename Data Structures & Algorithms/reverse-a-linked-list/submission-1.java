/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class Solution {
  public ListNode reverseList(ListNode head) {
    return reverseLinkedList(head, null);
  }

  public ListNode reverseLinkedList(ListNode head, ListNode tail) {
    if (head == null) {
      return tail;
    }
    ListNode nextHead = head.next;
    head.next = tail;
    return reverseLinkedList(nextHead, head);
  }
}
