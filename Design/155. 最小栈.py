class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.s = []
        self.min_s = [math.inf]


    def push(self, x: int) -> None:
        self.s.append(x)
        self.min_s.append(min(x, self.min_s[-1]))

    def pop(self) -> None:
        if len(self.s):
            self.s.pop()
            self.min_s.pop()


    def top(self) -> int:
        if len(self.s):
            return self.s[-1] 
        

    def getMin(self) -> int:
        if len(self.s):
            return self.min_s[-1] 


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()