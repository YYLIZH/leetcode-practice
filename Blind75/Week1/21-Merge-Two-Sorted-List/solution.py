# Definition for singly-linked list.
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeTwoLists(
        self, list1: Optional[ListNode], list2: Optional[ListNode]
    ) -> Optional[ListNode]:
        if not list1 and not list2:
            return None

        if not list1:
            return list2

        if not list2:
            return list1

        # Take one as prime, use two pointer
        list1_curr = list1
        list2_curr = list2

        if list1.val <= list2.val:
            prime = ListNode(val=list1.val, next=None)
            list1_curr = list1.next
        else:
            prime = ListNode(val=list2.val, next=None)
            list2_curr = list2.next

        prime_curr = prime
        while list1_curr and list2_curr:
            if list1_curr.val <= list2_curr.val:
                prime_curr.next = list1_curr
                prime_curr = prime_curr.next
                list1_curr = list1_curr.next
            else:
                prime_curr.next = list2_curr
                prime_curr = prime_curr.next
                list2_curr = list2_curr.next

        # When while loop ends, list1 or list2 runs to end
        if list1_curr:
            prime_curr.next = list1_curr

        elif list2_curr:
            prime_curr.next = list2.curr

        return prime
