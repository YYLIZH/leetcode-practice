class StackArray:
    def __init__(self) -> None:
        self._top = -1
        self.capacity = 1
        self.stack = []

    def _double_capacity(self):
        self.capacity *= 2

    def top(self):
        if self.is_empty():
            print("Stack is empty.")
            return -1

        return self.stack[self._top]

    def push(self, x: int):
        if self._top == self.capacity - 1:
            self._double_capacity()

        self.stack.append(x)
        self._top += 1

    def is_empty(self):
        return self._top == -1

    def pop(self):
        if self.is_empty():
            print("Stack is empty")
            return -1

        self._top -= 1

    def getsize(self):
        return self._top + 1


if __name__ == "__main__":
    s = StackArray()
    s.pop()
    s.push(14)
    s.push(9)
    print(f"\nTop: {s.top()}\nSize: {s.getsize()}")
    s.push(7)
    print(f"\nTop: {s.top()}\nSize: {s.getsize()}")
    s.pop()
    s.pop()
    print(f"\nTop: {s.top()}\nSize: {s.getsize()}")
    s.pop()
    print(f"\nTop: {s.top()}\nSize: {s.getsize()}")
