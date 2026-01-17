/**
 * Definition for singly-linked list.
 * class ListNode(var _x: Int = 0) {
 *   var next: ListNode = null
 *   var x: Int = _x
 * }
 */

object Solution {
    def hasCycle(head: ListNode): Boolean = {
        if(head == null)return false
        var tortoise = head
        var hare = head.next
        while (tortoise != null && hare != null && tortoise != hare){
            tortoise = tortoise.next
            hare = if (hare.next != null) (hare.next).next else null
        }
        return (tortoise == hare && tortoise != null)
    }
}