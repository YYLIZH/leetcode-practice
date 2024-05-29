import sys


class ListNode:
    def __init__(self, data: int) -> None:
        self.data = data
        self.next: ListNode = None


class LinkedList:
    def __init__(self) -> None:
        self.first: ListNode = None

    def print_list(self):
        if self.first is None:
            print("List is empty")
            return

        curr = self.first
        while curr:
            sys.stdout.write(str(curr.data) + " ")
            curr = curr.next
        sys.stdout.write("\n")

    def push_front(self, x: int):
        newNode = ListNode(x)
        newNode.next = self.first
        self.first = newNode

    def push_back(self, x: int):
        newNode = ListNode(x)
        if not self.first:
            self.first = newNode
            return

        curr = self.first
        while curr.next:
            curr = curr.next

        curr.next = newNode

    def delete(self, x: int):
        curr = self.first
        prev = None

        while curr and curr.data != x:
            prev = curr
            curr = curr.next

        if not curr:
            print(f"There is no {x} in list.")

        elif curr == self.first:
            self.first = curr.next
            del curr

        else:
            prev.next = curr.next
            del curr

    def clear(self):
        while self.first:
            curr = self.first
            self.first = self.first.next
            del curr

    def reverse(self):
        if self.first is None or self.first.next is None:
            return

        prev = None
        curr = self.first
        prec = self.first.next

        while prec:
            curr.next = prev
            prev = curr
            curr = prec
            prec = prec.next

        curr.next = prev
        self.first = curr


if __name__ == "__main__":
    list = LinkedList()
    # 建立LinkedList的object
    list.print_list()
    # 目前list是空的
    list.delete(4)
    # list是空的, 沒有4
    list.push_back(5)
    # list: 5
    list.push_back(3)
    # list: 5 3
    list.push_front(9)
    # list: 9 5 3
    list.print_list()
    # 印出:  9 5 3
    list.push_back(4)
    # list: 9 5 3 4
    list.delete(9)
    # list: 5 3 4
    list.print_list()
    # 印出:  5 3 4
    list.push_front(8)
    # list: 8 5 3 4
    list.print_list()
    # 印出:  8 5 3 4
    list.reverse()
    # list: 4 3 5 8
    list.print_list()
    # 印出:  4 3 5 8
    list.clear()
    # 清空list
    list.print_list()
    # 印出: List is empty.
