class CQueue:

    def __init__(self):
        self.inStack = []
        self.outStack = []

    def appendTail(self, value: int) -> None:
        self.inStack.append(value)

    def deleteHead(self) -> int:
        if not len(self.outStack) and not len(self.inStack):
            return -1
        if len(self.outStack):
            return self.outStack.pop()
        while len(self.inStack):
            self.outStack.append(self.inStack.pop())
        return self.outStack.pop()


# Your CQueue object will be instantiated and called as such:
# obj = CQueue()
# obj.appendTail(value)
# param_2 = obj.deleteHead()