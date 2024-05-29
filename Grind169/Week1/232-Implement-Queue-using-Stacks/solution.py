class MyQueue:
    def __init__(self):
        # input and output are two stacks
        self.input = []
        self.output = []

    def push(self, x: int) -> None:
        self.input.append(x)

    def pop(self) -> int:
        if len(self.output) > 0:
            return self.output.pop()
        else:
            while len(self.input) > 0:
                self.output.append(self.input.pop())
            return self.output.pop()

    def peek(self) -> int:
        if len(self.output) > 0:
            return self.output[-1]
        else:
            while len(self.input) > 0:
                self.output.append(self.input.pop())
            return self.output[-1]

    def empty(self) -> bool:
        if len(self.input) == 0 and len(self.output) == 0:
            return True
        return False
