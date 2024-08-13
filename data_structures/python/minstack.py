class MinStack:
    def __init__(self) -> None:
        self.data=[]
        self.minstack=[]

    def push(self,x:int):
        self.data.append(x)
        if len(self.minstack==0) or x<self.minstack[-1]:
            self.minstack.append(x)
        else:
            self.minstack.append(self.minstack[-1])

    def pop(self):
        