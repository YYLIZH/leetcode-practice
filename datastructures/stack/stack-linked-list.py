class StackNode:
    def __init__(self, data: int = 0, next_node=None) -> None:
        self.data = data
        self.next: StackNode = next_node


class StackList:
    def __init__(self) -> None:
        self._top: StackNode = None
        self.size: int = 0

    def is_empty(self)->bool:
        return self.size == 0

    def push(self, x: int):
        if self.is_empty():
            self._top = StackNode(x)
            self.size += 1
            return

        newNode = StackNode(x)
        newNode.next = self._top
        self._top = newNode
        self.size += 1

    def pop(self):
        if self.is_empty():
            print("Stack is empty.\n")
            return
        
        self._top=self._top.next
        self.size-=1

    def top(self)->int:
        if self.is_empty():
            print("Stack is empty.\n")
            return -1
        
        return self._top.data

    def get_size(self)->int:
        return self.size
    


if __name__=="__main__":
    s=StackList()
    s.pop()
    s.push(32)
    s.push(4)
    print(f"\nTop: {s.top()}\nSize: {s.get_size()}")
    s.push(15)
    print(f"\nTop: {s.top()}\nSize: {s.get_size()}")
    s.pop()
    s.pop()
    print(f"\nTop: {s.top()}\nSize: {s.get_size()}")
    s.pop()
    print(f"\nTop: {s.top()}\nSize: {s.get_size()}")

    
